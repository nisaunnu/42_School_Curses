#pragma once

# include "Server.hpp"
# include "Client.hpp"
# include "ErrorCodes.hpp"

void sendError(Client* client, ErrorCode errorCode, const std::string& target = "");

std::vector<std::string>	split(const std::string& input, char delimiter);
std::string 				trim(const std::string &str);
int 						checkNickname(std::string &nickname);
void						signals(void);
