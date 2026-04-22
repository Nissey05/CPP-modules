#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(const MutantStack &cpy);
		MutantStack &operator=(const MutantStack &cpy);
		MutantStack(const MutantStack &&cpy);
		MutantStack &operator=(const MutantStack &&cpy);

		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;
		reverse_iterator rbegin();
		const_reverse_iterator crbegin() const;
		reverse_iterator rend();
		const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"