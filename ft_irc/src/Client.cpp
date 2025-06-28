#include "Client.hpp"
#include "Channel.hpp"

Client::Client(void)
	: _fd(-1), _logged(false), _isRegistered(false), _username(""), _nickname(""), _hostname(""), _buffer("") {}

Client::Client(std::string username, std::string nickname, int fd)
	: _fd(fd), _logged(false), _isRegistered(false), _username(username), _nickname(nickname) {}

Client::Client(const Client &src) { *this = src; }

Client	&Client::operator=(const Client &src)
{
	if (this != &src)
	{
		this->_fd = src._fd;
		this->_username = src._username;
		this->_nickname = src._nickname;
		this->_logged = src._logged;
		this->_isRegistered = src._isRegistered;
		this->_buffer = src._buffer;
	}
	return (*this);
}

Client::~Client(void) {}

int						Client::getFd(void)	const				{ return this->_fd;           }
std::string				Client::getBuffer(void)					{ return this->_buffer;       }
std::string				Client::getUsername(void)	const		{ return this->_username;     }
std::string				Client::getNickname(void)				{ return this->_nickname;     }
std::string				Client::getRealname(void)				{ return this->_realname;     }
std::string				Client::getHostname(void)				{ return this->_hostname;     }
std::string				Client::getServername(void)				{ return this->_servername;   }
bool					Client::getRegistered(void)				{ return this->_isRegistered; }
bool					Client::getLogged(void)					{ return this->_logged;       }
std::vector<Channel *>	Client::getChannels(void)				{ return _channels;           }

Channel		*Client::getChannel(Channel *channel)
{
	std::vector<Channel *>::iterator	it;
	it = std::find(_channels.begin(), _channels.end(), channel);

	if (it != _channels.end())
		return (*it);
	return (NULL);
}

void	Client::setFd(int fd)						{ this->_fd = fd;              }
void	Client::setLogged(bool value)				{ this->_logged = value;       }
void	Client::setRegistered(bool value)			{ this->_isRegistered = value; }
void	Client::setRealName(std::string str)		{ this->_realname = str;       }
void	Client::setHostname(std::string str)		{ this->_hostname = str;       }
void	Client::setBuffer(std::string &buffer)		{ this->_buffer = buffer;      }
void	Client::setServername(std::string str)		{ this->_servername = str;     }
void	Client::setNickname(std::string &nickname)	{ this->_nickname = nickname;  }
void	Client::setUsername(std::string &username)	{ this->_username = username;  }

void	Client::addChannel(Channel *channel)
{
	if (channel != NULL)
		_channels.push_back(channel);
}

void	Client::rmChannel(std::string &channelName)
{
	for (size_t i = 0; i < _channels.size(); ++i)
	{
		if (_channels[i]->getName() == channelName)
		{
			_channels.erase(_channels.begin() + i);
			break ;
		}
	}
}

void	Client::freeBuffer(void) { this->_buffer.clear(); }

void	Client::disconnect(void)
{
	if (_fd != -1)
	{
		close(_fd);
		_fd = -1;
	}

	for (size_t i = 0; i < _channels.size(); ++i)
	{
		_channels[i]->rmClient(this);
		if (_channels.empty())
			delete _channels[i];
	}

	_channels.clear();
}

void Client::reply(const std::string& message)
{
	std::string fullMessage = message + "\r\n";
	send(_fd, fullMessage.c_str(), fullMessage.length(), 0);
}

Server*	Client::getServer(void) const 		{ return _server;   }
void	Client::setServer(Server* server)	{ _server = server; }
