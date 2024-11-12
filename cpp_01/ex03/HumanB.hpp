#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;

	public:
		HumanB(std::string _name) : name(_name), weapon(0) {};

		void	attack() const;
		void	setWeapon(const Weapon &weapon);
};

#endif
