#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include "BitcoinExchange.hpp"

bool	isValidValue(const std::string& str, float& out)
{
	char*	end;

	out = std::strtof(str.c_str(), &end);

	if (*end != '\0' || out < 0)
		return false;

	return true;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream	input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange	btc("data.csv");
	std::string		line;

	std::getline(input, line);

	while (std::getline(input, line))
	{
		std::istringstream	ss(line);
		std::string			date, valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		date.erase(date.find_last_not_of(" \t") + 1);
		date.erase(0, date.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		float	value;
		if (!isValidValue(valueStr, value))
		{
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!btc.isValidDate(date)) 
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}


		if (value > 1000.0f)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			float	rate = btc.getRateForDate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
		catch (const BitcoinException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
