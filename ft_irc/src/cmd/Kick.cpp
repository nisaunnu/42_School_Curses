#include "Server.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

static bool	checkIfSenderIsOperator(Client *client, const std::vector<std::string> &channels)
{
	bool										isOperatorInAnyChannel = false;
	std::vector<std::string>::const_iterator	it = channels.begin();

	for (; it != channels.end(); ++it)
	{
		Channel *channel = Server::getInstance().getCheckChannel(*it);
		if (channel && channel->checkOperatorClient(client))
		{
			isOperatorInAnyChannel = true;
			break;
		}
	}

	if (!isOperatorInAnyChannel)
	{
		sendError(client, ERR_CHANOPRIVSNEEDED, client->getNickname());
		return false;
	}

	return true;
}

static bool	checkInput(std::vector<std::string> &tokens)
{
	size_t	count = 0;

	for (size_t i = 0; i < tokens.size(); ++i )
	{
		if (tokens[i][0] == '#' || tokens[i][0] == '&')
			count++;
	}

	if (count > 1)
		return false;

	return true;
}

static std::vector<std::string>	extractChannels(std::string &channels)
{
	std::vector<std::string>	parsed;
	bool						isInvalid = false;

	parsed = split(channels, ',');
	for (size_t i = 0; i < parsed.size(); ++i)
	{
		if (parsed[i][0] != '#' && parsed[i][0] != '&')
		{
			isInvalid = true;
			break ;
		}
	}

	return ((isInvalid) ? std::vector<std::string>() : parsed);
}

static void extractReason(std::string &args, std::string &reason)
{
	size_t	reasonIndex = args.find(':');

	if (reasonIndex == std::string::npos)
	{
		reason = "No reason specified.";
		return ;
	}
	reason = args.substr(reasonIndex + 1);
	args = args.substr(0, reasonIndex);
}

static std::string	makeBroadcastMessage(Client *client, const std::string &channelName, std::string &userToKick, std::string &reason)
{
	std::ostringstream	oss;

	oss << ":" << client->getNickname() << "!" << client->getUsername()
		<< "@" << "127.0.0.1" << " KICK " << channelName << " "
		<< userToKick << " :" << reason << "\r\n";

	return (oss.str());
}

void	kick(Client *client, std::string &args)
{
	if (args.empty())
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return ;
	}

	std::string	reason;
	extractReason(args, reason);
	std::vector<std::string>	tokens = split(args, ' ');

	if (tokens.size() != 2 || !checkInput(tokens))
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return ;
	}

	std::vector<std::string>	channels  = extractChannels(tokens[0]);
	std::vector<std::string>	usersList = split(tokens[1], ',');

	if (channels.size() != usersList.size())
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return;
	}

	if (!checkIfSenderIsOperator(client, channels))
		return ;

	for (size_t i = 0; i < channels.size(); ++i)
	{
		const std::string	&channelName = channels[i];
		std::string			&userToKick = usersList[i];

		Channel	*channel = Server::getInstance().getCheckChannel(channelName);

		if (!channel)
		{
			sendError(client, ERR_NOSUCHCHANNEL, client->getNickname() + " " + channelName);
			continue ;
		}

		if (!channel->checkOperatorClient(client))
		{
			sendError(client, ERR_CHANOPRIVSNEEDED, channelName);
			continue ;
		}

		if (userToKick.empty())
		{
			sendError(client, ERR_NEEDMOREPARAMS, "No user specified for channel " + channelName);
			continue ;
		}

		if (userToKick[0] == ':')
			userToKick = userToKick.substr(1);

		Client	*toKick = channel->checkClient(userToKick);

		if (!toKick)
		{
			sendError(client, ERR_NOTONCHANNEL, channelName);
			continue ;
		}

		std::string	msg = makeBroadcastMessage(client, channelName, userToKick, reason);

		channel->broadcast(client, msg);
		channel->rmClient(toKick);
	}
}
