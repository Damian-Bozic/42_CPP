/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:09 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/13 14:31:12 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

// https://cppreference.com/w/cpp/container/stack.htm
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
