#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <vector>
# include <iostream>

class Server;
class Client;

class Command
{
	protected:
		Server	*server;

	public:
		Command(Server *server) : server(server) {}
		virtual	~Command() {}

		virtual void	execute(Client *client, std::vector<std::string> arguments) = 0;
};

#endif
