/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:58:24 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/02 16:58:25 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <exception>
# include <iostream>

template <typename T>
void easyfind(T container, int to_find);

class easyfindError : public std::exception
{
	public:
		const char *what() const throw();
};

# include "easyfind.tpp"
#endif
