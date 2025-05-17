#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget*	clone() const;
};

#endif
