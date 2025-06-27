#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

Channel::Channel() {}

Channel::~Channel() {}

Channel::Channel(const std::string &channelName, const std::string &key, Client *creator) : _topic("")
{
	if (channelName.empty() || (channelName[0] != '&' && channelName[0] != '#'))
		throw std::invalid_argument("Invalid channel name. Must start with '&' or '#'.");

	_name = channelName;
	_operatorClients.push_back(creator);

	_modes['i'] = false;
	_modes['t'] = false;
	_modes['l'] = false;

	if (key.empty())
	{
		_key = "";
		_modes['k'] = false;
	}
	else
	{
		_key = key;
		_modes['k'] = true;
	}

	_limit = -1;
	std::cout << "Channel '" << _name << "' created by " << creator->getNickname() << ".\n";
}

bool	Channel::getMode(char key)
{
	if (_modes.find(key) != _modes.end())
		return _modes[key];

	return false;
}

bool	Channel::getOperatorList(std::string nickname)
{
	std::string	names;

	for (size_t i = 0; i < _operatorClients.size(); ++i)
	{
		names += _operatorClients[i]->getNickname();
		if (i != _operatorClients.size() - 1)
			names += " ";
	}

	if (names.find(nickname) != std::string::npos)
		return true;

	return false;
}

bool	Channel::getClientList(std::string nickname)
{
	std::string	names;

	for (size_t i = 0; i < _clients.size(); ++i)
	{
		names += _clients[i]->getNickname();
		if (i != _clients.size() - 1)
			names += " ";
	}

	if (names.find(nickname) != std::string::npos)
		return true;

	return false;
}

std::string	Channel::getUserList()
{
	std::string	names;

	for (size_t i = 0; i < _operatorClients.size(); ++i)
	{
		names += _operatorClients[i]->getNickname();
		if (i != _operatorClients.size() - 1)
			names += " ";
	}

	if (_clients.size() >= 1)
		names += " ";

	for (size_t i = 0; i < _clients.size(); ++i)
	{
		names += _clients[i]->getNickname();
		if (i != _clients.size() - 1)
			names += " ";
	}

	return names;
}

std::string		Channel::getName()				{ return this->_name ;                                }
std::string		Channel::getTopic()				{ return this->_topic;                                }
size_t			Channel::getOperatorCount()		{ return (_operatorClients.size());                   }
size_t			Channel::getUserCount()			{ return (_clients.size() + _operatorClients.size()); }

bool	Channel::isKeyProtected()								{ return (getMode('k'));                                                                               }
bool	Channel::checkKey(const std::string &str)	const		{ return (_key == str);                                                                                }
bool	Channel::isInvited(const std::string &nickname)	const	{ return std::find(_clientsInvited.begin(), _clientsInvited.end(), nickname) != _clientsInvited.end(); }
void	Channel::setTopic(const std::string &topic)				{ this->_topic = topic;                                                                                }
void	Channel::setKey(std::string str)						{ this->_key = str;                                                                                    }
void	Channel::setLimit(int limit)							{ this->_limit = limit;                                                                                }

void	Channel::setMode(char mode, bool status, int value)
{
	(void)value;
	_modes[mode] = status;
	std::cout << "Channel " << _name << " mode " << mode << " set to " << (status ? "ON" : "OFF") << ".\n";
}

bool	Channel::checkOperatorClient(Client *client)
{
	for (size_t i = 0; i < this->_operatorClients.size(); ++i)
	{
		if (this->_operatorClients[i]->getNickname() == client->getNickname())
			return true;
	}
	return false;
}

Client	*Channel::checkClient(std::string nickname)
{
	if (this->_clients.empty())
		return NULL;

	for (size_t i = 0; i < this->_clients.size(); ++i)
	{
		if (this->_clients[i]->getNickname() == nickname)
			return this->_clients[i];
	}

	for (size_t i = 0; i < this->_operatorClients.size(); ++i)
	{
		if (this->_operatorClients[i]->getNickname() == nickname)
			return this->_operatorClients[i];
	}

	return NULL;
}

bool	Channel::isFull()								{ return ((this->_clients.size() + this->_operatorClients.size()) == static_cast<u_long>(this->_limit) ? true : false ); }
bool	Channel::isEmpty()	const						{ return (this->_clients.empty() && this->_operatorClients.empty());                                                     }
void	Channel::addClientsInvited(std::string client)	{ this->_clientsInvited.push_back(client);                                                                               }

void	Channel::addClient(Client *client)
{
	if (std::find(_clients.begin(), _clients.end(), client) == _clients.end() &&
		std::find(_operatorClients.begin(), _operatorClients.end(), client) == _operatorClients.end()) {
		if (this->isFull())
		{
			sendError(client, ERR_CHANNELISFULL, client->getNickname() + " " + this->getName());
			return;
		}
		_clients.push_back(client);
	}
}

void	Channel::addOperatorClient(Client *client)
{
	if (std::find(_clients.begin(), _clients.end(), client) == _clients.end() &&
		std::find(_operatorClients.begin(), _operatorClients.end(), client) == _operatorClients.end())
	{
		if (this->isFull())
		{
			sendError(client, ERR_CHANNELISFULL, client->getNickname() + " " + this->getName());
			return;
		}
	}

	if (std::find(_operatorClients.begin(), _operatorClients.end(), client) == _operatorClients.end()) {}
		_operatorClients.push_back(client);

	std::vector<Client*>::iterator it = std::find(_clients.begin(), _clients.end(), client);
	if (it != _clients.end())
		_clients.erase(it);
}

void Channel::removeOperatorClient(Client *client)
{
	this->_operatorClients.erase(std::remove(this->_operatorClients.begin(), this->_operatorClients.end(), client),
								 this->_operatorClients.end());
}

void	Channel::rmClient(Client *client)
{
	for (size_t i = 0; i < _clients.size(); ++i)
	{
		if (_clients[i]->getNickname() == client->getNickname())
		{
			_clients.erase(_clients.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < _operatorClients.size(); ++i)
	{
		if (_operatorClients[i]->getNickname() == client->getNickname())
		{
			_operatorClients.erase(_operatorClients.begin() + i);
			break;
		}
	}
}

std::vector<int>	Channel::listFdClients()
{
	std::vector<int>					list;
	std::vector<Client *>::iterator		it = _clients.begin();

	for (; it != _clients.end(); ++it)
		list.push_back((*it)->getFd());

	it = _operatorClients.begin();
	for (; it != _operatorClients.end(); ++it)
		list.push_back((*it)->getFd());

	return (list);
}

void	Channel::broadcast(Client *sender, std::string &msg)
{
	for (size_t i = 0; i < _clients.size(); ++i)
	{
		if (_clients[i] != sender)
			send(_clients[i]->getFd(), msg.c_str(), msg.size(), 0);
	}

	for (size_t i = 0; i < _operatorClients.size(); ++i)
	{
		if (_operatorClients[i] != sender)
			send(_operatorClients[i]->getFd(), msg.c_str(), msg.size(), 0);
	}
}

void	Channel::RPLTOPIC(Client *client)
{
	std::ostringstream oss;

	oss << ":" << Server::getServerName() << " " << ((this->_topic.empty()) ? 331 : 332)
		<< " " << client->getNickname() << " " << this->getName() << " :"
		<< ((this->_topic.empty()) ? "No topic is set" : this->_topic)
		<< "\n";

	std::string msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);
}

void	Channel::RPL_NAMREPLY(Client *client)
{
	std::string	list = this->getUserList();

	std::ostringstream oss;

	oss << ":" << Server::getServerName() << " " << 353 << " "
		<< client->getNickname() << " = " << this->getName()
		<< " :" << list << "\n";
	std::string msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);

	oss.str("");
	oss.clear();
	oss << ":" << Server::getServerName() << " " << 366 << " "
		<< client->getNickname() << " " << this->getName()
		<< " :End of NAMES list." << "\r\n";
	msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);
}

void Channel::cmdHelp(Client *client)
{
	std::ostringstream oss;

	oss << "\nAvailable commands in the channel:\n"
		<< "  /JOIN <channel> [key]               - Join a channel\n"
		<< "  /WHO <channel>                      - List users in a channel\n"
		<< "  /TOPIC <channel> [topic]            - Set or view the topic of a channel\n"
		<< "  /INVITE <nickname> <channel>        - Invite a user to a channel\n"
		<< "  /KICK <channel> <nickname>          - Kick a user from a channel\n"
		<< "  /MODE <channel> <mode> [parameters] - Change channel modes (set: + , remove: -)\n"
		<< "    · i: Set/remove invitation only channel\n"
		<< "    · t: Set/remove restrictions of the TOPIC command for channel operators\n"
		<< "    · k: Set/remove channel password\n"
		<< "    · o: Give/take channel operator permission\n"
		<< "    · l: Set/remove user limit on channel\n"
		<< "  /PRIVMSG <nickname>[<channel>] <message> - Send a private message to a user\r\n";
	std::string msg = oss.str();

	send(client->getFd(), msg.c_str(), msg.size(), 0);
}
