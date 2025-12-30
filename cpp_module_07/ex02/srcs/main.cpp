/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:00:52 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/30 14:00:53 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	// try
	// {
	// 	Array<int>* a = new Array<int>();
	// 	std::cout << (*a)[0] << std::endl;
	// 	return (0);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
try
{
	Array<int>* array_of_size_0 = new Array<int>();
	Array<int>* array_of_size_250 = new Array<int>(250);

	std::cout << (*array_of_size_250)[0] << std::endl;
	delete array_of_size_250;
	delete array_of_size_0;
	return (0);
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
	return (1);
}

// int main(void)
// {
// 	int * a = new int(); 
// 	std::cout << *a << std::endl;
// 	return (0);
// }