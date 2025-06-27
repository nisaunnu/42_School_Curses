#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <map>
# include <set>
# include <vector>
# include <sstream>
# include <iostream>
# include <unistd.h>
# include <algorithm>

class Channel;
class Server;

class Client
{
	private:
		int							_fd;
		bool						_logged;
		bool						_isRegistered;
		std::string					_servername;
		std::string					_username;
		std::string 				_nickname;
		std::string					_hostname;
		std::string					_realname;
		std::string					_buffer;
		std::vector<Channel *>		_channels;
		Server*						_server;

	public:
		Client(void);
		Client(std::string username, std::string nickname, int fd);
		Client(const Client &src);
		Client &operator=(const Client &src);
		~Client();

		int			getFd(void) const;
		Server*		getServer(void) const;

		bool		getLogged(void);
		bool		getRegistered(void);

		std::string	getBuffer(void);
		std::string	getNickname(void);
		std::string	getRealname(void);
		std::string	getHostname(void);
		std::string	getServername(void);
		std::string	getUsername(void) const;

		Channel					*getChannel(Channel *channel);
		std::vector<Channel *>	getChannels(void);

		void	setFd(int fd);
		void	setLogged(bool value);
		void	setRegistered(bool value);
		void	setRealName(std::string str);
		void	setHostname(std::string str);
		void	setBuffer(std::string &buffer);
		void	setServername(std::string str);
		void	setNickname(std::string &nickname);
		void	setUsername(std::string &username);
		void	setServer(Server* server);

		bool	NICK(std::string &str);
		bool	NAME(std::string &str);

		void	disconnect(void);
		void	freeBuffer(void);
		void	addChannel(Channel *channel);
		void	rmChannel(std::string &channelName);
		void    reply(const std::string& message);
};

#endif
