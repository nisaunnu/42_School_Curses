#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string _type) : _type(_type) {};
		~Weapon() {};
		void 				setType(const std::string& _type);
		const std::string&	getType() const;
};

#endif
