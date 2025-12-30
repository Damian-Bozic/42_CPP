/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:20:37 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 19:20:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstdio>

template<typename D, typename F>
void iter(D* arr_ptr, const size_t arr_len, F function)
{
	size_t i = 0;

	if (!arr_ptr || !arr_len)
		return;
	while (i < arr_len)
	{
		function(arr_ptr[i]);
		i++;
	}
}

#endif
