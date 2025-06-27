#include <sstream>
#include "Server.hpp"
#include "Client.hpp"
#include "ErrorCodes.hpp"

void	who(Client *client, std::string &value)
{
	if (!client)
		return;

	std::istringstream iss(value);
	std::string channelName;
	if (!(iss >> channelName))
	{
		std::stringstream ss;
		ss << ERR_NEEDMOREPARAMS;
		std::string error = ":" + std::string(SERVER_NAME) + " " +
						  ss.str() + " " +
						  client->getNickname() + " WHO :Not enough parameters\r\n";
		send(client->getFd(), error.c_str(), error.length(), 0);
		return;
	}

	Server::getInstance().handleWho(client, channelName);
}
