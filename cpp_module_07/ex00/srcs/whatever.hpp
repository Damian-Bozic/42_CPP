/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:00:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 19:02:00 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename D>
void swap(D &a, D &b)
{
	D temp;

	temp = a;
	a = b;
	b = temp;
}


template<typename D>
D min(D &a, D &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename D>
D max(D &a, D &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
