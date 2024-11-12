#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon) {};

		void	attack() const;
};

#endif
