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
	try
	{
		Array<int>* int_array_of_size_0 = new Array<int>();
		Array<int>* int_array_of_size_250 = new Array<int>(250);
		Array<float> *float_array_of_size_10 = new Array<float>(10);

		std::cout << "Array250[21] = " << (*int_array_of_size_250)[21] << std::endl;
		(*int_array_of_size_250)[21] = 42;
		(*int_array_of_size_250)[64] = 128;
		std::cout << "Array250[21] = " << (*int_array_of_size_250)[21] << std::endl;
		std::cout << "Array250[64] = " << (*int_array_of_size_250)[64] << std::endl;
		*int_array_of_size_0 = *int_array_of_size_250;
		std::cout << "Array0[21] = " << (*int_array_of_size_0)[21] << std::endl;
		std::cout << "Array0[64] = " << (*int_array_of_size_0)[64] << std::endl;
		std::cout << "Float Array[6] = " << (*float_array_of_size_10)[6] << std::endl;
		(*float_array_of_size_10)[6] = 123.321f;
		std::cout << "Float Array[6] = " << (*float_array_of_size_10)[6] << std::endl;

		delete int_array_of_size_250;
		delete int_array_of_size_0;
		delete float_array_of_size_10;
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (1);
}
