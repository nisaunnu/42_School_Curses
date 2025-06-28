#include "Server.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

static std::string	makeBroadcastMessage(Client *client, const std::string &channelName, std::string &topic)
{
	std::ostringstream	oss;

	oss << ":" << client->getNickname() << "!" << client->getUsername()
		<< "@" << "127.0.0.1" << " TOPIC " << channelName
		<< " :" << topic << "\r\n";

	return (oss.str());
}

void	topic(Client *client, std::string &arg)
{

	size_t			spacePos = arg.find(' ');
	std::string		channelName = (spacePos == std::string::npos) ? arg : arg.substr(0, spacePos);
	std::string		topic = (spacePos == std::string::npos) ? "" : arg.substr(spacePos + 1);

	if (channelName.empty() || (channelName[0] != '#' && channelName[0] != '&'))
	{
		sendError(client, ERR_NEEDMOREPARAMS, "Invalid channel name");
		return ;
	}

	Channel	*channel = Server::getInstance().getCheckChannel(channelName);
	if (!channel)
	{
		sendError(client, ERR_NOSUCHCHANNEL, client->getNickname() + " " + channelName);
		return ;
	}

	if (topic.empty())
		channel->RPLTOPIC(client);
	else
	{
		if (channel->getMode('t') && !channel->checkOperatorClient(client))
		{
			sendError(client, ERR_CHANOPRIVSNEEDED, client->getNickname());
			return ;
		}
		if (topic[0] != ':')
		{
			sendError(client, ERR_NEEDMOREPARAMS, "Topic must start with ':'");
			return;
		}

		topic = topic.substr(1);
		channel->setTopic(topic);

		std::string	msg = makeBroadcastMessage(client, channelName, topic);
		channel->broadcast(client, msg);
    }
}
