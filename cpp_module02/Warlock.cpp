#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!" << std::endl;
}

void	Warlock::introduce() const
{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

const std::string&	Warlock::getName() const  { return this->_name;  }
const std::string&	Warlock::getTitle() const { return this->_title; }

void	Warlock::setTitle(const std::string& other) { this->_title = other; }

void	Warlock::learnSpell(ASpell* spell)          { _spellbook.learnSpell(spell);      }
void	Warlock::forgetSpell(std::string spellName) { _spellbook.forgetSpell(spellName); }

void	Warlock::launchSpell(std::string spellName, ATarget& target)
{
	ASpell*	spell = _spellbook.createSpell(spellName);

	if (spell != nullptr)
	{
		spell->launch(target);
		delete spell;
	}
}
