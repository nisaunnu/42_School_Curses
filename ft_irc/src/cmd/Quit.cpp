#include "Server.hpp"
#include "Channel.hpp"

void	quit(Client *client, std::string &message)
{
	std::string				response = ":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getHostname() + " QUIT :" + message + "\r\n";
	std::vector<Channel *>	channels = client->getChannels();

	send(client->getFd(), response.c_str(), response.size(), 0);

	for (size_t i = 0; i < channels.size(); ++i)
	{
		channels[i]->broadcast(client, response);
		channels[i]->rmClient(client);
	}

	Server	&server = Server::getInstance();

	server.removeClientFromServer(client);
	server.removeClientFromPolls(client->getFd());

	std::cout << "Client '" << client->getNickname() << "' disconnected from server." << std::endl;
	client->disconnect();
	delete client;
}
