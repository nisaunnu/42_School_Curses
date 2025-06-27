#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include <set>
# include <ctime>
# include <poll.h>
# include <vector>
# include <sstream>
# include <fcntl.h>
# include <cstdlib>
# include <netdb.h>
# include <limits.h>
# include <iostream>
# include <unistd.h>
# include <algorithm>
# include <sys/types.h>
# include <arpa/inet.h>
# include <sys/socket.h>

# include "Utils.hpp"
# include "Bot.hpp"

class Client;
class Channel;

class Server
{
	private:
		static	Server			instance;
		static	std::string		_srvName;
		static	bool			_initialized;

		std::string				_pass;
		int 					_port;
		int 					_listeningSocket;
		Bot*					_bot;

		std::vector<Channel *>	_channels;
		std::vector<Client *>	_clients;
		std::vector<pollfd>		pollfds;

	public:
		Server();
		Server(const Server &src);
		Server	&operator=(const Server *src);
		~Server();

		static std::string	getServerName() { return _srvName; }

		int				start();
		void			cleanServer();
		static Server	&getInstance();
		static void		init(int port, const std::string &pass);

		int				getPort(void);
		std::string		getPass(void);
		Bot*			getBot(void) { return _bot; }

		Client			*getClientBySocket(int fd);
		Client			*getClientByNickname(std::string nickname);
		Channel			*getCheckChannel(const std::string &name);

		std::vector<Client *>	getClients(void);
		std::vector<Channel *>	getChannels(Client *client);

		void		addChannel(Channel *channel);
		void		removeClientFromPolls(int fd);
		void		removeChannel(Channel *channel);
		void		removeClientFromServer(Client *client);
		void		handleWho(Client *client, const std::string &channelName);
		void		handleMode(Client *client, const std::string &channelName);
		void		broadcastMessage(const std::string& target, const std::string& message);
};

void 	parser(Client *client, std::string str);
void 	parsingbuffer(char *buffer, Client *client);

void	mode(Client *client, std::string &str);
void	join(Client *client, std::string& args);
void	kick(Client *client, std::string& args);
void	pass(Client *client, std::string &pass);
void	user(Client *client, std::string &pass);
void	who(Client *client, std::string &value);
void	topic(Client *client, std::string& args);
void	quit(Client *client, std::string &message);
void	nick(Client *client, std::string &nickname);
void	privMsg(Client *sender, std::string &value);
void	invite(Client *client, std::string &invitation);

#endif
