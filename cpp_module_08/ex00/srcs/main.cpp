/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:58:16 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/02 16:58:16 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> a_container_woaho;
	a_container_woaho.push_back(2);
	a_container_woaho.push_back(5);	
	a_container_woaho.push_back(4);	
	a_container_woaho.push_back(1);	
	for (int i = 1; i <= 8; i++)
	{
		try
		{
			easyfind(a_container_woaho, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
