#include <vector>
#include <iostream>
#include "Server.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

void handleModeI(Channel *channel, Client *client, char s)
{
	std::string	response = ":" + client->getNickname() + " MODE " + channel->getName() + " " + (s == '-' ? "-" : "+") + "i\r\n";

	channel->setMode('i', s == '+', 0);
	channel->broadcast(client, response);

	send(client->getFd(), response.c_str(), response.size(), 0);
}

void handleModeT(Channel *channel, Client *client, char s)
{
	std::string	response = ":" + client->getNickname() + " MODE " + channel->getName() + " " + (s == '-' ? "-" : "+") + "t\r\n";

	channel->setMode('t', s == '+', 0);
	channel->broadcast(client, response);

	send(client->getFd(), response.c_str(), response.size(), 0);
}

void handleModeK(Channel *channel, Client *client, char s, std::string key = "")
{
	key = trim(key);
	std::string	response = ":" + client->getNickname() + " MODE " + channel->getName() + " " + (s == '-' ? "-" : "+") + "k " + (!key.empty() ? key : std::string()) + "\r\n";
	channel->setMode('k', s == '+', 0);

	if (s == '-')
		channel->setKey("");
	else
		channel->setKey(key);

	channel->broadcast(client, response);
	send(client->getFd(), response.c_str(), response.size(), 0);
}

void handleModeO(Channel *channel, Client *client, char s, std::string nickname)
{
	nickname = trim(nickname);
	Client	*target = Server::getInstance().getClientByNickname(nickname);

	if (!target)
	{
		sendError(client, ERR_NOTONCHANNEL, nickname);
		return;
	}

	std::string	response = ":" + client->getNickname() + " MODE " + channel->getName() + " " + (s == '-' ? "-" : "+") + "o " + nickname + "\r\n";
	if (s == '-')
	{
		if (channel->checkOperatorClient(target))
		{
			if (channel->getOperatorCount() == 1 && target == client)
			{
				std::string	response("Cannot remove the last operator from the channel\r\n");
				send(client->getFd(), response.c_str(), response.size(), 0);
				return;
			}
			channel->removeOperatorClient(target);
			channel->addClient(target);
			channel->broadcast(client, response);
			send(client->getFd(), response.c_str(), response.size(), 0);
		}
	}
	else
	{
		if (!channel->checkOperatorClient(target))
		{
			channel->addOperatorClient(target);
			channel->broadcast(client, response);
			send(client->getFd(), response.c_str(), response.size(), 0);
		}
	}
}

void handleModeL(Channel *channel, Client *client, char s, std::string limitStr = "")
{
	limitStr = trim(limitStr);
	int	limit = 0;

	std::string	response = ":" + client->getNickname() + " MODE " + channel->getName() + " " + (s == '-' ? "-" : "+") + "l " + (!limitStr.empty() ? limitStr : std::string()) + "\r\n";
	channel->setMode('l', s == '+', 0);

	if (s == '+')
	{
		std::stringstream	ss(limitStr);
		if (!(ss >> limit) || limit <= 0)
		{
			sendError(client, ERR_NEEDMOREPARAMS, "Invalid limit value");
			return;
		}
		channel->setLimit(limit);
	}
	else
		channel->setLimit(-1);

	channel->broadcast(client, response);
	send(client->getFd(), response.c_str(), response.size(), 0);
}

void mode(Client *client, std::string &str)
{

	std::vector<std::string>	words = split(str, ' ');
	if (words.size() < 2 )
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return;
	}

	Channel	*channel = Server::getInstance().getCheckChannel(words[0]);
	if (!channel)
	{
		sendError(client, ERR_NOSUCHCHANNEL, client->getNickname() + " " + words[0]);
		return;
	}

	if (!channel->checkOperatorClient(client))
	{
		sendError(client, ERR_CHANOPRIVSNEEDED, words[0]);
		return;
	}

	char	s = '+';
	for (size_t i = 0; i < words[1].size(); ++i)
	{
		while (words[1][i] == '+' || words[1][i] == '-')
			s = words[1][i++];

		switch (words[1][i])
		{
			case 'i':
				handleModeI(channel, client, s);
				break;
			case 't':
				handleModeT(channel, client, s);
				break;
			case 'k':
				if (s == '+' && words.size() < 3)
				{
					sendError(client, ERR_NEEDMOREPARAMS, "Not enough parameters for 'k' mode");
					return;
				}
				if (s == '-')
					handleModeK(channel, client, s);
				else
					handleModeK(channel, client, s, words[2]);
				std::cout << "FLAG " << std::endl;
				break;
			case 'o':
				if (words.size() < 3)
				{
					sendError(client, ERR_NEEDMOREPARAMS, "Not enough parameters for 'o' mode");
					return;
				}
				handleModeO(channel, client, s, words[2]);
				break;
			case 'l':
				if (s == '+' && words.size() < 3)
				{
					sendError(client, ERR_NEEDMOREPARAMS, "Not enough parameters for 'l' mode");
					return;
				}
				if (s == '+')
					handleModeL(channel, client, s, words[2]);
				else
					handleModeL(channel, client, s);
				break;
			default:
				sendError(client, ERR_UNKNOWNMODE, std::string(1, words[1][i]));
				break;
		}
	}
}
