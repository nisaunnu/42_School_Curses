#include "Data.hpp"

Data::Data() : _age(0), _name(""), _score(0.0) {}
Data::Data(const Data& other) { *this = other; }
Data::~Data() {}

Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		_age = other._age;
		_name = other._name;
		_score = other._score;
	}
	return *this;
}

int			Data::getAge() const   { return _age;   }
std::string	Data::getName() const  { return _name;  }
double		Data::getScore() const { return _score; }

void	Data::setAge(int age)                  { _age = age;     }
void	Data::setName(const std::string& name) { _name = name;   }
void	Data::setScore(double score)           { _score = score; }
