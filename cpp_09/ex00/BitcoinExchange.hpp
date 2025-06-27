#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

		void	loadDatabase(const std::string& dbFile);

	public:
		BitcoinExchange(const std::string& dbFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		bool	isValidDate(const std::string& date) const;
		float	getRateForDate(const std::string& date) const;
};

class BitcoinException : public std::exception
{
	private:
		std::string	_msg;

	public:
		BitcoinException(const std::string& msg) throw();

		virtual const char*	what() const throw();
		virtual	~BitcoinException() throw();
};

#endif
