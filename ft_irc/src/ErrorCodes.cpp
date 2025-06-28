#include "ErrorCodes.hpp"

std::map<ErrorCode, std::string>	createErrorMessages()
{
	std::map<ErrorCode, std::string>	modes;

	modes[ERR_NOSUCHNICK]       = "No such nick/channel";
	modes[ERR_NOSUCHCHANNEL]    = "No such channel";
	modes[ERR_NORECIPIENT]      = "No recipient given (PRIVMSG)";
	modes[ERR_NOTEXTTOSEND]     = "No text to send";
	modes[ERR_NONICKNAMEGIVEN]  = "No nickname given";
	modes[ERR_ERRONEUSNICKNAME] = "Erroneus nickname";
	modes[ERR_NICKNAMEINUSE]    = "Nickname is already in use";
	modes[ERR_NICKCOLLISION]    = "Nickname collision KILL";
	modes[ERR_NOTONCHANNEL]     = "You're not on that channel";
	modes[ERR_USERONCHANNEL]    = "is already on channel";
	modes[ERR_NOLOGIN]          = "User not logged in";
	modes[ERR_NOTREGISTERED]    = "You have not registered";
	modes[ERR_NEEDMOREPARAMS]   = "Not enough parameters";
	modes[ERR_ALREADYREGISTRED] = "You may not reregister";
	modes[ERR_PASSWDMISMATCH]   = "Password incorrect";
	modes[ERR_UNKNOWNMODE]      = "Unknown mode";
	modes[ERR_INVITEONLYCHAN]   = "Cannot join channel (+i)";
	modes[ERR_CHANNELISFULL]    = "Cannot join channel (+l)";
	modes[ERR_BADCHANNELKEY]    = "Cannot join channel (+k)";
	modes[ERR_CHANOPRIVSNEEDED] = "You're not channel operator";
	modes[ERR_FILENOTFOUND]     = "File not found";
	modes[ERR_FILETRANSFERFAIL] = "File transfer failed";
	modes[RPL_FILESENT]         = "File sent successfully";

	return modes;
}

const	std::map<ErrorCode, std::string>	ErrorMessages = createErrorMessages();

std::string ERR_FILE_NOT_FOUND(const std::string& nickname, const std::string& filename)
{
	return ":" + std::string(SERVER_NAME) + " 404 " + nickname + " " + filename + " :File not found";
}

std::string ERR_FILE_TRANSFER_FAILED(const std::string& nickname, const std::string& filename)
{
	return ":" + std::string(SERVER_NAME) + " 405 " + nickname + " " + filename + " :File transfer failed";
}

std::string RPL_FILE_SENT(const std::string& nickname, const std::string& receiver, const std::string& filename)
{
	return ":" + std::string(SERVER_NAME) + " 200 " + nickname + " " + receiver + " " + filename + " :File sent successfully";
}
