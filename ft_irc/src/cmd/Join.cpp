#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

static std::string	toLowerCase(const std::string &str)
{
	std::string	result = str;

	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

static bool	isValidChannelName(std::string &name)
{
	if (name[0] == '#' || name[0] == '&')
		return (true);

	return (false);
}

static std::string	makeBroadcastMessage(Client *client, std::string &channelName)
{
	std::ostringstream	oss;

	oss << ":" << client->getNickname() << "!"
		<< client->getUsername() << "@" << client->getHostname() << " JOIN :"
		<< channelName << "\r\n";

	return (oss.str());
}


void	join(Client *client, std::string& args)
{
	if (args.empty())
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return ;
	}

	std::vector<std::string>	tokens = split(args, ' ');
	std::vector<std::string>	channels = split(tokens[0], ',');
	std::vector<std::string>	keys = (tokens.size() > 1)
		? split(tokens[1], ',')
		: std::vector<std::string>();

	for (size_t i = 0; i < channels.size(); ++i)
	{
		std::string	channelName = channels[i];
		std::string	key = (i < keys.size()) ? keys[i] : "";

		if (!isValidChannelName(channelName))
		{
			sendError(client, ERR_NOSUCHCHANNEL, client->getNickname() + " " + channelName);
			continue ;
		}

		channelName = toLowerCase(channelName);

		Channel	*channel = Server::getInstance().getCheckChannel(channelName);
		if (!channel)
		{
			channel = new Channel(channelName, key, client);
			Server::getInstance().addChannel(channel);
		}
		else
		{
			if (channel->getMode('i') && !channel->isInvited(client->getNickname()))
			{
				sendError(client, ERR_INVITEONLYCHAN, client->getNickname() + " " + channelName);
				continue ;
			}
			if (channel->isKeyProtected() && !channel->checkKey(key))
			{
				sendError(client, ERR_BADCHANNELKEY, client->getNickname() + " " + channelName);
				continue ;
			}
			if (channel->isFull())
			{
				sendError(client, ERR_CHANNELISFULL, client->getNickname() + " " + channelName);
				continue ;
			}
			channel->addClient(client);
		}
		std::string message = makeBroadcastMessage(client, channelName);

		send(client->getFd(), message.c_str(), message.size(), 0);
		channel->broadcast(client, message);
		channel->RPLTOPIC(client);
		channel->RPL_NAMREPLY(client);
		channel->cmdHelp(client);
	}
}
