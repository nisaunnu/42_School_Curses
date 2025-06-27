#include <ctime>
#include <cctype>
#include <sstream>
#include <iostream>
#include "Server.hpp"
#include "Client.hpp"
#include "Bot.hpp"

Bot::Bot(Server* server) : _server(server)
{
	_nickname = "IRC_Bot";
	_username = "ircbot";
	_realname = "IRC Bot";
}

Bot::~Bot() {}

std::string Bot::getCurrentTime() const
{
	char	buffer[80];
	time_t	now = time(NULL);
	struct	tm* timeinfo = localtime(&now);

	strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", timeinfo);
	return std::string(buffer);
}

std::string Bot::getHelpMessage() const
{
	std::string helpMessage = "\n\nIRC Bot Commands:\r\n";
	helpMessage += "\t!help - Shows all IRC commands\r\n";
	helpMessage += "\t!help <command> - Shows usage of a specific IRC command\r\n";
	helpMessage += "\t!help commands - Lists all available IRC commands\r\n";
	helpMessage += "\t!ping - Ping the bot and get a 'Pong' response\r\n";
	helpMessage += "\t!time - Shows current date and time (in DD.MM.YYYY HH:MM:SS format)";

	return helpMessage;
}

std::string Bot::getCommandHelp(const std::string& command) const
{
	std::string cmd = command;
	for (std::string::iterator it = cmd.begin(); it != cmd.end(); ++it)
		*it = toupper(*it);

	if (cmd == "COMMANDS")
	{
		std::string cmdList = "Available IRC Commands:\r\n";
		cmdList += "\tINVITE    JOIN       KICK    MODE\n\tNICK      PRIVMSG    QUIT    SENDFILE\n\tTOPIC     USER       WHO\n";
		return cmdList;
	}
	else if (cmd == "JOIN")
		return "Usage: JOIN <channel> [keys], joins the channel";
	else if (cmd == "PRIVMSG")
		return "Usage: PRIVMSG <target> <message>, sends a message to target (user or channel)";
	else if (cmd == "NICK")
		return "Usage: NICK <nickname>, changes your nickname";
	else if (cmd == "USER")
		return "Usage: USER <username> <hostname> <servername> :<realname>, sets user information";
	else if (cmd == "QUIT")
		return "Usage: QUIT [message], disconnects from the server";
	else if (cmd == "MODE")
		return "Usage: MODE <target> <modes>, changes modes for a channel or user";
	else if (cmd == "TOPIC")
		return "Usage: TOPIC <channel> [topic], sets or views the topic of a channel";
	else if (cmd == "INVITE")
		return "Usage: INVITE <nickname> <channel>, invites a user to a channel";
	else if (cmd == "KICK")
		return "Usage: KICK <channel> <user> [reason], removes a user from a channel";
	else if (cmd == "WHO")
		return "Usage: WHO <channel>, shows users in a channel";
	else if (cmd == "SENDFILE")
		return "Usage: SENDFILE <nickname> <filename>, sends a file to a user";
	else
		return "Command not found. Use \"!help commands\" to see all available commands.";
}

void Bot::handleCommand(const std::string& command, Client* client)
{
	std::string cmd = command;
	std::string param;
	std::string::size_type spacePos = command.find(' ');

	if (spacePos != std::string::npos)
	{
		cmd = command.substr(0, spacePos);
		param = command.substr(spacePos + 1);
	}

	if (cmd == "!ping")
		sendMessage(client->getNickname(), "Pong");
	else if (cmd == "!time")
	{
		std::string currentTime = getCurrentTime();
		sendMessage(client->getNickname(), currentTime);
	}
	else if (cmd == "!help")
	{
		if (!param.empty())
		{
			std::string helpMessage = getCommandHelp(param);
			sendMessage(client->getNickname(), helpMessage);
		}
		else
		{
			std::string helpMessage = getHelpMessage();
			sendMessage(client->getNickname(), helpMessage);
		}
	}
}

void Bot::sendMessage(const std::string& target, const std::string& message)
{
	std::string fullMessage = ":" + _nickname + " PRIVMSG " + target + " :" + message + "\r\n";
	_server->broadcastMessage(target, fullMessage);
}

const std::string& Bot::getNickname() const { return _nickname; }
