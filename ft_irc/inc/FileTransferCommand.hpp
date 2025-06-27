#ifndef FILETRANSFERCOMMAND_HPP
# define FILETRANSFERCOMMAND_HPP

# include <vector>
# include <iostream>

# include "FileTransfer.hpp"

class FileTransferCommand
{
	private:
		FileTransfer	fileTransfer;

	public:
		FileTransferCommand();

		bool				handleFileTransfer(const std::string& receiver, const std::string& filename, const std::vector<char>& fileData);
		std::string			parseFileTransferCommand(const std::string& command);
		std::vector<char>	prepareFileForTransfer(const std::string& filepath);
};

#endif
