#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() { _targetMap.clear(); }

void		TargetGenerator::learnTargetType(ATarget* target)
{
	if (target != nullptr)
	{
		std::map<std::string, ATarget *>::iterator	targetIterator = _targetMap.find(target->getType());

		if (targetIterator == _targetMap.end())
			_targetMap[target->getType()] = target;
	}
}

void		TargetGenerator::forgetTargetType(std::string const & targetType)
{
	std::map<std::string, ATarget *>::iterator	targetIterator = _targetMap.find(targetType);

	if (targetIterator != _targetMap.end())
		_targetMap.erase(targetType);
}

ATarget*	TargetGenerator::createTarget(std::string const & targetType)
{
	std::map<std::string, ATarget *>::iterator	targetIterator = _targetMap.find(targetType);

	if (targetIterator != _targetMap.end())
		return targetIterator->second->clone();
	return nullptr;
}
