#include "Bot.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

Server		Server::instance;
bool		Server::_initialized = false;
std::string	Server::_srvName = "novapair.server.com";

Server::Server() : _pass("default"), _port(0), _bot(NULL) {}

Server::~Server()
{
	if (this->_listeningSocket > 0)
		close(_listeningSocket);

	if (_bot)
		delete _bot;

	cleanServer();
	std::cout << "Server destroyed..." << std::endl;
}

void	Server::init(int port, const std::string &pass)
{
	if (_initialized)
	{
		std::cout << "Server is already running" << std::endl;
		return ;
	}

	if (port < 1024 || port > 49151)
		throw std::invalid_argument("Invalid port number");

	instance._port = port;
	instance._pass = pass;
	instance._bot = new Bot(&instance);
	_initialized = true;

	std::cout << "Server is running" << std::endl;
}

void	Server::cleanServer()
{
	for (size_t i = 0; i < _clients.size(); ++i)
		delete _clients[i];
	_clients.clear();

	for (size_t i = 0; i < _channels.size(); ++i)
		delete _channels[i];
	_channels.clear();
}

int		Server::start()
{
	this->_listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_listeningSocket == -1)
	{
		std::cerr << "Error creating a socket" << std::endl;
		return 1;
	}

	sockaddr_in	hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(this->_port);
	hint.sin_addr.s_addr = INADDR_ANY;

	int yes = 1;
	if (setsockopt(this->_listeningSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
		std::cerr << "setsockopt" << std::endl;

	if (bind(this->_listeningSocket, (struct sockaddr*)&hint, sizeof(hint)) == -1)
	{
		std::cerr << "Error binding IP/Port" << std::endl;
		return 1;
	}

	if (listen(this->_listeningSocket, FD_SETSIZE) == -1)
	{
		std::cerr << "Error listening" << std::endl;
		return 1;
	}

	pollfd	listeningPoll;
	listeningPoll.revents = 0;
	listeningPoll.events = POLLIN;
	listeningPoll.fd = this->_listeningSocket;

	pollfds.push_back(listeningPoll);

	while(42)
	{
		int pollCount = poll(pollfds.data(), pollfds.size(), -1);
		if (pollCount == -1)
		{
			std::cerr << "Error doing poll" << std::endl;
			break ;
		}

		for (size_t i = 0; i < pollfds.size(); ++i)
		{
			if (pollfds[i].revents & POLLIN)
			{
				if (pollfds[i].fd == this->_listeningSocket)
				{
					sockaddr_in clientSock;
					socklen_t clientSize = sizeof(clientSock);
					int clientSocket = accept(this->_listeningSocket, (sockaddr*)&clientSock, &clientSize);

					if (clientSocket == -1)
					{
						std::cerr << "Error accepting client" << std::endl;
						continue;
					}
					std::cout << "New connection established" << std::endl;

					Client *newClient = new Client("", "", clientSocket);
					_clients.push_back(newClient);

					pollfd clientPoll;
					clientPoll.fd = clientSocket;
					clientPoll.events = POLLIN;
					clientPoll.revents = 0;
					pollfds.push_back(clientPoll);
				}
				else
				{
					char buffer[1024] = {0};
					int received = recv(pollfds[i].fd, buffer, sizeof(buffer) - 1, 0);

					if (received <= 0)
					{
						std::cout << "Client disconnected" << std::endl;

						Client *client = getClientBySocket(pollfds[i].fd);
						if (client)
						{
							removeClientFromServer(client);
							delete client;
						}

						close(pollfds[i].fd);
						pollfds.erase(pollfds.begin() + i);
						--i;
					}
					else
					{
						buffer[received] = '\0';
						Client *client = getClientBySocket(pollfds[i].fd);
						if (client)
						{
							std::string message(buffer);
							parsingbuffer(buffer, client);
						}
					}
				}
			}
		}
	}
	close(this->_listeningSocket);
	return 0;
}

Channel	*Server::getCheckChannel(const std::string &name)
{
	for (size_t i = 0; i < _channels.size(); ++i)
	{
		if (_channels[i]->getName() == name)
			return (_channels[i]);
	}
	return (NULL);
}

Client	*Server::getClientByNickname(std::string nickname)
{
	for (size_t i = 0; i < _clients.size(); ++i)
	{
		if (_clients[i]->getNickname() == nickname)
			return (_clients[i]);
	}
	return (NULL);
}

Client	*Server::getClientBySocket(int fd)
{
	for (size_t i = 0; i < _clients.size(); ++i)
	{
		if (_clients[i]->getFd() == fd)
			return (_clients[i]);
	}
	return (NULL);
}

std::vector<Channel *>	Server::getChannels(Client *client)
{
	std::vector<Channel *>	channels;

	if (client == NULL)
		return _channels;

	for (std::vector<Channel *>::iterator it = this->_channels.begin(); it != this->_channels.end(); ++it)
	{
		if ((*it)->checkClient(client->getNickname()))
		{
			channels.push_back(*it);
		}
	}

	return channels;
}

Server&					Server::getInstance()                { return (instance);                                  }
std::string				Server::getPass(void)                { return this->_pass;                                 }
int						Server::getPort(void)                { return this->_port;                                 }
std::vector<Client *>	Server::getClients(void)             { return _clients;                                    }
void					Server::addChannel(Channel *channel) { Server::getInstance()._channels.push_back(channel); }

void	Server::removeClientFromPolls(int fd)
{
	std::vector<pollfd>::iterator it = pollfds.begin();

	for (; it != pollfds.end(); ++it)
	{
		if (it->fd == fd)
		{
			pollfds.erase(it);
			break ;
		}
	}
}

void	Server::removeClientFromServer(Client *client)
{
	if (!client) return ;

	std::vector<Channel *> channels = Server::getInstance().getChannels(NULL);

	if (!channels.empty())
	{
		for (size_t i = 0; i < channels.size(); ++i)
		{
			channels[i]->rmClient(client);
			if (channels[i]->isEmpty())
				removeChannel(channels[i]);
		}
	}
	_clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
}

void	Server::removeChannel(Channel *channel)
{
	_channels.erase(std::remove(_channels.begin(), _channels.end(), channel), _channels.end());
	delete channel;
}

void	Server::handleMode(Client *client, const std::string &channelName)
{
	std::ostringstream oss;

	oss << ":" << this->_srvName << " 324 " << client->getNickname()
		<< " " << channelName << " +nt" << "\r\n";

	std::string msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);

	oss.str("");
	oss.clear();

	oss << ":" << this->_srvName << " 329 " << client->getNickname()
		<< " " << channelName << " " << std::time(0) << "\r\n";

	msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);
}

void	Server::handleWho(Client *client, const std::string &channelName)
{
	if (!client)
		return;

	Channel	*channel = getCheckChannel(channelName);
	if (!channel)
	{
		std::stringstream ss;
		ss << ERR_NOSUCHCHANNEL;
		std::string	error = ":" + std::string(SERVER_NAME) + " " +
						  ss.str() + " " +
						  client->getNickname() + " " + channelName + " :No such channel\r\n";
		send(client->getFd(), error.c_str(), error.length(), 0);
		return;
	}

	std::vector<Client *>	channelClients = channel->getClients();
	for (size_t i = 0; i < channelClients.size(); ++i)
	{
		Client	*target = channelClients[i];
		std::stringstream ss;
		ss << RPL_WHOREPLY;
		std::string whoReply = ":" + std::string(SERVER_NAME) + " " +
							 ss.str() + " " +
							 client->getNickname() + " " +
							 channelName + " " +
							 target->getUsername() + " " +
							 target->getHostname() + " " +
							 std::string(SERVER_NAME) + " " +
							 target->getNickname() + " H :0 " +
							 target->getRealname() + "\r\n";
		send(client->getFd(), whoReply.c_str(), whoReply.length(), 0);
	}

	std::stringstream ss;
	ss << RPL_ENDOFWHO;
	std::string	endOfWho = ":" + std::string(SERVER_NAME) + " " +
						  ss.str() + " " +
						  client->getNickname() + " " +
						  channelName + " :End of WHO list\r\n";
	send(client->getFd(), endOfWho.c_str(), endOfWho.length(), 0);
}

void	Server::broadcastMessage(const std::string& target, const std::string& message)
{
	Client*	client = getClientByNickname(target);

	if (client)
		send(client->getFd(), message.c_str(), message.length(), 0);
}
