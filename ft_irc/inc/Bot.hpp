#ifndef BOT_HPP
# define BOT_HPP

# include <iostream>

class Client;
class Server;

class Bot
{
	private:
		Server*		_server;
		std::string	_nickname;
		std::string	_username;
		std::string	_realname;

	public:
		Bot(Server* server);
		~Bot();

		const std::string&	getNickname() const;
		std::string			getCurrentTime() const;
		std::string			getHelpMessage() const;
		std::string			getCommandHelp(const std::string& command) const;

		void	handleCommand(const std::string& command, Client* client);
		void	sendMessage(const std::string& target, const std::string& message);
};

#endif
