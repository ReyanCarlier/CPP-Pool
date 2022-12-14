#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void) : MutantStack<T, Container>::stack() {};
		MutantStack(const MutantStack<T, Container> &src) : MutantStack<T, Container>::stack(src) {};
		virtual ~MutantStack(void) {};
		MutantStack &operator=(MutantStack const &M) {
			if (this != &M) {
				this->MutantStack<T, Container>::operator=(M);
			}
			return *this;
		};

		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		iterator begin(void) {
			return this->c.begin();
		};
		iterator end(void) {
			return this->c.end();
		};
};

#endif