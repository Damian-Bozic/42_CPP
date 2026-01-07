/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:59:33 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/02 16:59:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void easyfind(T container, int to_find)
{
	typename T::iterator iterator_to_contained_value;

	iterator_to_contained_value = find(container.begin(), container.end(), to_find);
	if (iterator_to_contained_value == container.end())
		throw (easyfindError());
	std::cout << "easyfind has found something!!: "
		<< *iterator_to_contained_value << std::endl;
}
const char *easyfindError::what() const throw()
{
	return("easyfind threw");
}
