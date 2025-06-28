#include "Utils.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

bool	isValidPort(const std::string &portStr)
{
	if (portStr.empty())
		return false;

	for (size_t i = 0; i < portStr.size(); ++i)
	{
		if (!std::isdigit(portStr[i]))
			return false;
	}

	long	port = std::strtol(portStr.c_str(), NULL, 10);

	if (port >= 1 && port <= 65535)
		return true;

	return false;
}

bool	checkPass(const std::string &pass)
{
	if (pass.find(' ') != std::string::npos)
	{
		std::cerr << "Password cannot contain spaces." << std::endl;
		return false;
	}

	return true;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Please use ./ircserv <port> <password>" << std::endl;
		return (1);
	}

	std::string	port(argv[1]);
	std::string	pass(argv[2]);

	if ( !isValidPort(port))
	{
		std::cerr << "Please use correct port." << std::endl;
		return 1;
	}

	if ( !checkPass(pass))
		return 1;

	try
	{
		Server::init(std::atoi(port.c_str()), pass);
		Server	&server = Server::getInstance(); 
		signals();

		if (server.start() != 0)
		{
			std::cerr << "Failed to start the server." << std::endl;
			return (1);
		}
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
