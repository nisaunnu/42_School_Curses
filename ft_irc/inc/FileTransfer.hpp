#ifndef FILETRANSFER_HPP
# define FILETRANSFER_HPP

# include <vector>
# include <iostream>

class FileTransfer
{
	private:
		std::string	basePath;

	public:
		FileTransfer();
		~FileTransfer();

		bool				createUserDirectory(const std::string& username);
		bool				saveFile(const std::string& username, const std::string& filename, const std::vector<char>& fileData);
		std::vector<char>	readFile(const std::string& filepath);
};

#endif
