#include <iostream>
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

static Client	*checkClient(std::string &nickname)
{
	std::vector<Client *>	vclient = Server::getInstance().getClients();

	for (long unsigned int i = 0; i < vclient.size(); i++)
	{
		if (vclient[i]->getNickname() == nickname)
			return vclient[i];
	}

	return NULL;
}

void	privMsg(Client *sender, std::string &value)
{
	if (value.empty())
	{
		sendError(sender, ERR_NORECIPIENT);
		return;
	}

	value = trim(value);

	std::vector<std::string>	words = split(value, ' ');
	if (words[0].empty())
	{
		sendError(sender, ERR_NORECIPIENT);
		return;
	}

	std::string	message;
	if (words.size() > 1)
	{
		message = words[1];
		if (message.empty())
		{
			sendError(sender, ERR_NOTEXTTOSEND);
			return;
		}
		if (message.at(0) != ':')
		{
			sendError(sender, ERR_NOTEXTTOSEND);
			return;
		}
		message = message.substr(1);
		for (size_t i = 2; i < words.size(); i++)
			message += " " + words[i];
	}

	std::vector<std::string>	targets = split(words[0], ',');

	for (size_t	i = 0; i < targets.size(); i++)
	{
		Channel	*ctarget = Server::getInstance().getCheckChannel(targets[i]);
		Client	*target = checkClient(targets[i]);

		if (ctarget)
		{
			std::vector<int>	channelSockets = ctarget->listFdClients();

			for (size_t	j = 0; j < channelSockets.size(); j++)
			{
				int	socket = channelSockets[j];

				if (socket == sender->getFd())
					continue;

				std::string	fullMessage = ":" + sender->getNickname() + " PRIVMSG " + ctarget->getName() + " :" + message + "\r\n";
				send(socket, fullMessage.c_str(), fullMessage.size(), 0);
			}
		}
		else if (target)
		{
			int			targetSocket = target->getFd();
			std::string	fullMessage = ":" + sender->getNickname() + " PRIVMSG " + target->getNickname() + " :" + message + "\r\n";
			send(targetSocket, fullMessage.c_str(), fullMessage.size(), 0);
		}
		else
			sendError(sender, ERR_NOSUCHNICK, targets[0]);
	}
}
