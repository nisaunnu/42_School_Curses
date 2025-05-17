#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include <iostream>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *>	_targetMap;

	public:
	TargetGenerator();
	~TargetGenerator();

	void		learnTargetType(ATarget *);
	void		forgetTargetType(std::string const &);
	ATarget*	createTarget(std::string const &);
};

#endif
