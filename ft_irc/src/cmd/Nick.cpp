#include <iostream>
#include "Server.hpp"
#include "Client.hpp"
#include "Utils.hpp"
#include "ErrorCodes.hpp"

int	checkNickname(std::string &nickname)
{
	std::vector<Client *>	vclient = Server::getInstance().getClients();

	for (long unsigned int i = 0; i < vclient.size(); i++)
	{
		if (vclient[i]->getNickname() == nickname)
			return 1;
	}

	return 0;
}

static int	validateNick(std::string &nick)
{
	if (nick.size() > 9 || (nick[0] >= '0' && nick[0] <= '9') || nick[0] == '-')
		return 1;

	const char				validCharArray[] = {'-', '[', ']', '\\', '^', '_', '{', '}', '|'};
	const std::set<char>	validChar(validCharArray, validCharArray + sizeof(validCharArray) / sizeof(char));

	for (size_t i = 0; i < nick.size(); ++i)
	{
		if ((validChar.find(nick[i]) == validChar.end()) && (nick[i] < '0' || nick[i] > '9')
			&& (nick[i] < 'a' || nick[i] > 'z') && (nick[i] < 'A' || nick[i] > 'Z'))
			return 1;
	}

	return 0;
}

void	nick(Client *client, std::string &nickname)
{
	if (nickname.empty())
	{
		sendError(client, ERR_NONICKNAMEGIVEN);
		return;
	}

	if (validateNick(nickname))
	{
		sendError(client, ERR_ERRONEUSNICKNAME, nickname);
		return ;
	}

	if (!client->getNickname().empty() && nickname == client->getNickname())
	{
		sendError(client, ERR_NICKCOLLISION, nickname);
		return;
	}

	if (checkNickname(nickname))
	{
		sendError(client, ERR_NICKNAMEINUSE, nickname);
		nickname += "1";
		nick(client, nickname);
		return;
	}

	std::string	str = "";
	if (client->getNickname().empty())
	{
		str = "Introducing new nick \"" + nickname + "\"\n";
		send(client->getFd(), str.c_str(), str.size(), 0);
	}
	else
	{
		str = ":" + client->getNickname() + " NICK :" + nickname + "\n";
		send(client->getFd(), str.c_str(), str.size(), 0);
	}
	client->setNickname(nickname);
}
