#include "Utils.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ErrorCodes.hpp"

void makeInviterMessage(Client* client, const std::string &channelName, const std::string &invitedName)
{

	std::string	serverName = Server::getServerName();

	std::ostringstream	oss;
	oss << ":" << serverName << " " << 341
		<< " " << client->getNickname()
		<< " " << invitedName << " "
		<< channelName << "\r\n";

	std::string	msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);
}

void	makeInvitedMessage(Client *client, std::string channelName, Client *invited)
{

	std::ostringstream	oss;

	oss << ":" << client->getNickname() << "!"
		<< client->getUsername() << "@" << client->getHostname() << " INVITE " << invited->getNickname() << " " << channelName << "\r\n";

	std::string	msg = oss.str();
	send(invited->getFd(), msg.c_str(), msg.size(), 0);
}

void	invite(Client *client, std::string &invitation)
{
	std::vector<std::string>	words = split(invitation, ' ');

	if (words.size() < 2)
	{
		sendError(client, ERR_NEEDMOREPARAMS);
		return ;
	}

	std::string	inviter     = client->getNickname();
	std::string	invited     = words[0];
	std::string	channelName = words[1];

	Channel	*channel = Server::getInstance().getCheckChannel(channelName);

	if (!checkNickname(words[0]))
		sendError(client, ERR_NOSUCHNICK, invited);
	else if (!channel)
		sendError(client, ERR_NOSUCHCHANNEL, inviter + " " + channelName);
	else if (channel->getClientList(invited))
		sendError(client, ERR_USERONCHANNEL, client->getNickname() + " " + invited + " " + channelName);
	else if (!channel->getOperatorList(client->getNickname()))
		sendError(client, ERR_CHANOPRIVSNEEDED, channelName);
	else
	{
		channel->addClientsInvited(invited);
		Client *invited = Server::getInstance().getClientByNickname(words[0]);

		makeInviterMessage(client, channel->getName(), invited->getNickname());
		makeInvitedMessage(client, channel->getName(), invited);
	}
}
