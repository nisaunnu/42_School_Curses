#include <vector>
#include <sstream>
#include <iostream>
#include "Utils.hpp"
#include "Server.hpp"
#include "ErrorCodes.hpp"

static bool	checkRealname(std::string &name) { return !name.empty() && name[0] == ':'; }

static bool	checkServerName(std::string &name)
{
	std::string serverName = Server::getInstance().getServerName();

	if (name == "*")
	{
		name = serverName;
		return true;
	}
	return serverName == name;
}

static bool	isValidIp(std::string &host)
{
	if (host == "0")
	{
		std::string newHost = "127.0.0.1";
		host = newHost;
	}
	struct sockaddr_in	sa;

	return inet_pton(AF_INET, host.c_str(), &(sa.sin_addr)) != 0;
}

void	user(Client *client, std::string &args)
{
	if (client->getRegistered())
	{
		sendError(client, ERR_ALREADYREGISTRED);
		return;
	}

	if (!client->getLogged() )
		return ;

	std::vector<std::string>	tokens = split(args, ' ');
	if (tokens.size() < 4)
	{
		std::cerr << "USE: /USER <user> <hostname> <serverName> :<realname>" << std::endl;
		sendError(client, ERR_NEEDMOREPARAMS);
		return ;
	}

	std::string	username = tokens[0];
	std::string	hostname = tokens[1];
	std::string	servername = tokens[2];
	std::string	realname = tokens[3];

	if (!isValidIp(hostname))
	{
		sendError(client, ERR_NEEDMOREPARAMS, "Invalid ip");
		return ;
	}

	if (!checkServerName(servername))
	{
		sendError(client, ERR_NEEDMOREPARAMS, "Invalid server");
		return ;
	}

	if (!checkRealname(realname))
	{
		sendError(client, ERR_NEEDMOREPARAMS, "Invalid realname");
		return ;
	}

	client->setUsername(username);
	client->setHostname(hostname);
	client->setServername(servername);
	client->setRealName(realname);
	client->setRegistered(true);

	std::ostringstream	oss;
	oss << ":" << Server::getInstance().getServerName()
		<< " 001 " << client->getNickname() << " :Welcome to the IRC network, "
		<< client->getNickname() << "!" << client->getUsername() << "@"
		<< client->getHostname() << "\r\n";

	std::string msg = oss.str();
	send(client->getFd(), msg.c_str(), msg.size(), 0);
}
