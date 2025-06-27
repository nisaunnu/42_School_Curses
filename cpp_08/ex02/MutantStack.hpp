#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

# define RESET     "\033[0m"
# define BLUE      "\033[38;5;45m"

# define HEADER(txt) std::cout << std::endl << BLUE << "--- " << txt << " ---" << RESET << std::endl;

template	<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();

		iterator				begin();
		iterator				end();

		const_iterator			begin() const;
		const_iterator			end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
