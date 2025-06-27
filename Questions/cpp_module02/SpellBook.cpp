#include "ASpell.hpp"
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() { _spellMap.clear(); }

void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell != NULL)
	{
		std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spell->getName());

		if (spellIterator == _spellMap.end())
			_spellMap[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(std::string const & spellName)
{
	std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spellName);

	if (spellIterator != _spellMap.end())
	{
		delete spellIterator->second;
		_spellMap.erase(spellName);
	}
}

ASpell*	SpellBook::createSpell(std::string const & spellName)
{
	std::map<std::string, ASpell *>::iterator	spellIterator = _spellMap.find(spellName);

	if (spellIterator != _spellMap.end())
		return spellIterator->second->clone();
	return NULL;
}
