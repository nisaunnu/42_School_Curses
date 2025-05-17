#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

	public:
		Warlock(const std::string& _name, const std::string& _title);
		~Warlock();

		const std::string	&getName() const;
		const std::string	&getTitle() const;

		void	setTitle(const std::string& other);
		void	introduce() const;
};

#endif
