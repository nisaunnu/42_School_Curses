#include <sstream>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "FileTransfer.hpp"

FileTransfer::FileTransfer()
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		basePath = std::string(cwd);
}

FileTransfer::~FileTransfer() {}

bool FileTransfer::createUserDirectory(const std::string& username)
{
	std::string	userDir = basePath + "/" + username;

	if (mkdir(userDir.c_str(), 0755) == 0)
		return true;
	return false;
}

bool FileTransfer::saveFile(const std::string& username, const std::string& filename, const std::vector<char>& fileData)
{
	std::string	userDir = basePath + "/" + username;

	struct stat st;
	if (stat(userDir.c_str(), &st) != 0)
	{
		if (!createUserDirectory(username))
			return false;
	}

	std::string		filePath = userDir + "/" + filename;
	std::ofstream	file(filePath.c_str(), std::ios::binary);

	if (!file.is_open())
		return false;

	file.write(&fileData[0], fileData.size());
	file.close();
	return true;
}

std::vector<char> FileTransfer::readFile(const std::string& filepath)
{
	std::ifstream		file(filepath.c_str(), std::ios::binary);
	std::vector<char>	fileData;

	if (!file.is_open())
		return fileData;

	file.seekg(0, std::ios::end);
	std::streampos size = file.tellg();
	file.seekg(0, std::ios::beg);

	fileData.resize(static_cast<size_t>(size));
	file.read(&fileData[0], size);
	file.close();

	return fileData;
}
