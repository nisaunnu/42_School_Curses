#ifndef SENDFILE_HPP
# define SENDFILE_HPP

# include <vector>
# include <iostream>

# include "Command.hpp"

class Server;
class Client;

class SendFile : public Command
{
	public:
		SendFile(Server *server);
		~SendFile();

		void	execute(Client *client, std::vector<std::string> arguments);
};

#endif
