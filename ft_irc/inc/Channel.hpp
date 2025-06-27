#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <map>
# include <set>
# include <vector>
# include <sstream>
# include <unistd.h>
# include <iostream>
# include <unistd.h>
# include <algorithm>
# include <sys/types.h>
# include <sys/socket.h>


class Client;

class Channel
{
	private:
		std::string					_key;
		std::string					_name;
		std::string					_topic;
		std::map<char, bool>		_modes;
		std::vector<Client *>		_clients;
		std::vector<Client *>		_operatorClients;
		std::vector<std::string>	_clientsInvited;
		int							_limit;
		Channel();

	public:
		Channel(const std::string &channelName, const std::string &key, Client *creator);
		~Channel();

		std::string	getName();
		std::string	getTopic();
		std::string	getUserList();
		std::vector<Client *> getClients() const { return _clients; }

		size_t		getUserCount();
		size_t		getOperatorCount();

		bool		getMode(char key);
		bool		getClientList(std::string nickname);
		bool		getOperatorList(std::string nickname);

		void	setMode(char mode, bool status, int value);
		void	setKey(std::string str);
		void	setLimit(int limit);
		void	setTopic(const std::string &topic);

		bool	checkKey(const std::string &key) const;
		bool	checkOperatorClient(Client *client);
		Client	*checkClient(std::string nickname);

		bool	isFull();
		bool	isEmpty() const;
		bool	isKeyProtected();
		bool	isInvited(const std::string &nickname) const;

		void	addClient(Client *client);
		void	addOperatorClient(Client *client);
		void	addClientsInvited(std::string client);

		void	RPLTOPIC(Client *client);
		void	RPL_NAMREPLY(Client *client);

		void				cmdHelp(Client *client);
		void				rmClient(Client *client);
		void				removeOperatorClient(Client *client);
		void				broadcast(Client *sender, std::string &msg);
		std::vector<int>	listFdClients();
};

#endif
