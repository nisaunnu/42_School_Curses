#include "Bot.hpp"
#include "Server.hpp"
#include "SendFile.hpp"
#include "ErrorCodes.hpp"
#include <sstream>

static	void	sendfile(Client *client, std::string &value)
{
	if (client == NULL)
		return;

	std::istringstream	iss(value);
	std::string			receiver;
	std::string			filename;

	if (!(iss >> receiver >> filename)) {
		std::stringstream ss;
		ss << ERR_NEEDMOREPARAMS;
		std::string error = ":" + std::string(SERVER_NAME) + " " +
						  ss.str() + " " +
						  client->getNickname() + " SENDFILE :Not enough parameters";
		client->reply(error);
		return;
	}

	SendFile cmd(client->getServer());
	std::vector<std::string> args;
	args.push_back(receiver);
	args.push_back(filename);
	cmd.execute(client, args);
}

static	bool	handleLoginAndRegistration(Client *client, const std::string &cmd)
{
	if (client->getRegistered())
		return true;

	if (!client->getLogged() && cmd != "/PASS")
	{
		sendError(client, ERR_NOLOGIN);
		return false;
	}

	if ( client->getLogged() && !client->getRegistered() && cmd != "/NICK" && cmd != "/USER")
	{
		sendError(client, ERR_NOTREGISTERED);
		return false;
	}

	if ( client->getLogged() && client->getRegistered() && cmd != "/USER")
	{
		sendError(client, ERR_NOTREGISTERED);
		return false;
	}

	return true;
}

static	bool	validCommand(Client *client, std::string &value, std::string &cmd)
{
	if (client == NULL)
		return false;

	typedef void	(*cmdFunction)(Client *, std::string&);

	std::string	commands[12] = { "PASS", "NICK", "USER", "JOIN", "MODE", "TOPIC", "INVITE", "KICK", "PRIVMSG", "SENDFILE", "QUIT", "WHO" };
	cmdFunction	functions[12] = { pass, nick, user, join, mode, topic, invite, kick, privMsg, sendfile, quit, who };

	int index = 0;
	for (; index < 12; ++index)
	{
		if (cmd == '/' + std::string(commands[index]))
			break;
	}

	if (index < 12)
	{
		functions[index](client, value);
		return true;
	}
	else
		return false;
}

void	parser(Client *client, std::string str)
{
	if (!str.empty() && str[0] == '!')
	{
		std::string	cmd = str.substr(0, str.find_first_of(" \t"));
		if (cmd == "!ping" || cmd == "!time" || cmd == "!help")
		{
			Server::getInstance().getBot()->handleCommand(str, client);
			return;
		}
	}

	if (!str.empty() && str[0] != '/')
		str = "/" + str;

	size_t tab = str.find('/');
	if (tab == std::string::npos)
		return;

	std::string	cmd = str.substr(tab, str.find_first_of(" \t", tab) - tab);
	size_t		value_start = str.find_first_not_of(" \t", tab + cmd.size());
	std::string	value = (value_start == std::string::npos) ? "" : str.substr(value_start);
	value = trim(value);

	if (!handleLoginAndRegistration(client, cmd))
		return ;

	if (!cmd.empty() && !validCommand(client, value, cmd))
	{
		std::string response = cmd + " :Unknown command\r\n";
		send(client->getFd(), response.c_str(), response.size(), 0);
	}
}

void	parsingbuffer(char *buffer, Client *client)
{
	std::istringstream	stream(buffer);
	static std::string	line;
	std::string			temp;

	while (std::getline(stream, temp))
	{
		line += temp;
		temp.clear();
		if (stream.eof() && temp.empty())
			return ;

		if (line.find('\0') != std::string::npos)
			return ;

		if (line != "CAP LS 302\r")
			parser(client, trim(line));
		line.clear();
	}
}
