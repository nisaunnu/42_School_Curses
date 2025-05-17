#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget(const std::string& type): _type(type) {}

ATarget::~ATarget() {}

const std::string&	ATarget::getType() const { return this->_type; }

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
