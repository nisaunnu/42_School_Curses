#include <iostream>
#include <vector>
#include <sstream>
#include "FileTransferCommand.hpp"

FileTransferCommand::FileTransferCommand() : fileTransfer() {}

bool FileTransferCommand::handleFileTransfer(const std::string& receiver, const std::string& filename, const std::vector<char>& fileData)
{
	return fileTransfer.saveFile(receiver, filename, fileData);
}

std::vector<char> FileTransferCommand::prepareFileForTransfer(const std::string& filepath)
{
	return fileTransfer.readFile(filepath);
}

std::string FileTransferCommand::parseFileTransferCommand(const std::string& command)
{
	std::istringstream	iss(command);
	std::string			cmd;
	std::string			filename;
	std::string			receiver;

	if (iss >> cmd >> receiver >> filename)
	{
		if (cmd == "SENDFILE")
			return filename;
	}
	return "";
}
