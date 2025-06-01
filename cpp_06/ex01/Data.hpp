#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		int			_age;
		std::string	_name;
		double		_score;

	public:
		Data();
		Data(const Data& other);
		Data&	operator=(const Data& other);
		~Data();

		int			getAge() const;
		std::string	getName() const;
		double		getScore() const;

		void	setAge(int age);
		void	setScore(double score);
		void	setName(const std::string& name);
};

#endif
