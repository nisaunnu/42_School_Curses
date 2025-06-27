#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) { loadDatabase(dbFile); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	if (this != &other)
		_database = other._database;
	return *this;
}

void	BitcoinExchange::loadDatabase(const std::string& dbFile)
{
	std::ifstream	file(dbFile.c_str());
	if (!file)
		throw BitcoinException("Error: could not open database file.");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream	ss(line);
		std::string			date, valueStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
			continue;

		if (!isValidDate(date))
			continue;

		float				value;
		std::stringstream	valStream(valueStr);
		
		valStream >> value;
		if (valStream.fail() || !valStream.eof())
			continue;

		_database[date] = value;
	}
}

bool	BitcoinExchange::isValidDate(const std::string& date) const 
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int					year, month, day;
	char				dash1, dash2;
	std::istringstream	ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return false;

	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	static const int	daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int					maxDay = daysInMonth[month - 1];

	if (month == 2) 
	{
		bool	isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeap)
			maxDay = 29;
	}

	if (day > maxDay)
		return false;

	return true;
}

float	BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator	it = _database.find(date);
	if (it != _database.end())
		return it->second;

	it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return it->second;

	if (it == _database.begin())
		throw BitcoinException("Error: no earlier date found in database.");

	--it;
	return it->second;
}

BitcoinException::BitcoinException(const std::string& msg) throw() : _msg(msg) {}

BitcoinException::~BitcoinException() throw() {}

const char*	BitcoinException::what() const throw() { return _msg.c_str(); }
