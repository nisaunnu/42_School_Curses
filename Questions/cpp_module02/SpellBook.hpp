#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <map>
# include <iostream>
# include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell *>	_spellMap;

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *);
		void	forgetSpell(std::string const &);
		ASpell*	createSpell(std::string const &);
};

#endif
