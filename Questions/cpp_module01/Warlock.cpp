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

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell != nullptr)
	{
		std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spell->getName());

		if (spellIterator == _spellMap.end())
			_spellMap[spell->getName()] = spell->clone();
	}
}

void	Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spellName);

	if (spellIterator != _spellMap.end())
	{
		delete spellIterator->second;
		_spellMap.erase(spellName);
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget& target)
{
	std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spellName);

	if (spellIterator != _spellMap.end())
		spellIterator->second->launch(target);
}
