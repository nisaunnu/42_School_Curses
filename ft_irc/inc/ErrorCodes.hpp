#pragma once

# include <map>
# include <iostream>

# define SERVER_NAME "irc.local"

enum	ErrorCode
{
	ERR_NOSUCHNICK       = 401,
	ERR_NOSUCHCHANNEL    = 403,
	ERR_NORECIPIENT      = 411,
	ERR_NOTEXTTOSEND     = 412,
	ERR_NONICKNAMEGIVEN  = 431,
	ERR_ERRONEUSNICKNAME = 432,
	ERR_NICKNAMEINUSE    = 433,
	ERR_NICKCOLLISION    = 436,
	ERR_NOTONCHANNEL     = 442,
	ERR_USERONCHANNEL    = 443,
	ERR_NOLOGIN          = 444,
	ERR_NOTREGISTERED    = 451,
	ERR_NEEDMOREPARAMS   = 461,
	ERR_ALREADYREGISTRED = 462,
	ERR_PASSWDMISMATCH   = 464,
	ERR_CHANNELISFULL    = 471,
	ERR_UNKNOWNMODE      = 472,
	ERR_INVITEONLYCHAN   = 473,
	ERR_BADCHANNELKEY    = 475,
	ERR_CHANOPRIVSNEEDED = 482,
	ERR_FILENOTFOUND     = 404,
	ERR_FILETRANSFERFAIL = 405,
	RPL_FILESENT         = 200
};

extern const std::map<ErrorCode, std::string> ErrorMessages;

std::string ERR_FILE_NOT_FOUND(const std::string& nickname, const std::string& filename);
std::string ERR_FILE_TRANSFER_FAILED(const std::string& nickname, const std::string& filename);
std::string RPL_FILE_SENT(const std::string& nickname, const std::string& receiver, const std::string& filename);

# define RPL_WHOREPLY 352
# define RPL_ENDOFWHO 315
