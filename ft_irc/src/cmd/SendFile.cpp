#include <vector>
#include <sstream>
#include "Server.hpp"
#include "Client.hpp"
#include "SendFile.hpp"
#include "ErrorCodes.hpp"
#include "FileTransferCommand.hpp"

SendFile::SendFile(Server *server) : Command(server) {}

SendFile::~SendFile() {}

void SendFile::execute(Client *client, std::vector<std::string> arguments)
{
	std::string	receiver = arguments[0];
	std::string	filename = arguments[1];

	FileTransferCommand fileTransfer;
	std::vector<char> fileData = fileTransfer.prepareFileForTransfer(filename);

	if (fileData.empty())
	{
		client->reply(ERR_FILE_NOT_FOUND(client->getNickname(), filename));
		return;
	}

	if (fileTransfer.handleFileTransfer(receiver, filename, fileData))
		client->reply(RPL_FILE_SENT(client->getNickname(), receiver, filename));
	else
		client->reply(ERR_FILE_TRANSFER_FAILED(client->getNickname(), filename));
}

