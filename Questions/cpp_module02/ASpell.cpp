#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects): _name(name), _effects(effects) {}

ASpell::~ASpell() {}

std::string	ASpell::getName() const    { return this->_name;    }
std::string	ASpell::getEffects() const { return this->_effects; }

void	ASpell::launch(const ATarget& target) const { target.getHitBySpell(*this); }
