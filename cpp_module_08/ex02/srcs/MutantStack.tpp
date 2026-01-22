/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:23 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/13 14:31:23 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
typename std::stack<T>::container_type::iterator  MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator  MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}
