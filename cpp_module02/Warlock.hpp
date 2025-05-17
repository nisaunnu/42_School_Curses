#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <map>
# include <iostream>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		SpellBook	_spellbook;

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string&	getName() const;
		const std::string&	getTitle() const;

		void	setTitle(const std::string& other);

		void	introduce() const;

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget& target);
};

#endif
