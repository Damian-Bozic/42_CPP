/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:20:31 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 19:20:32 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <string>
#include <iostream>
#define CASE_DIFFERENCE 32
#define INT_MAX 2147483647

void ftToUpper(char &c)
{
	if (islower(c))
		c = c - CASE_DIFFERENCE;
}

void roundOddsUp(int &i)
{
	if (i % 2 == 1 && i != INT_MAX)
		i++;
}

template <typename D>
void increment(D &x)
{
    x++;
}

template <typename D>
void printConstX(D const &x) 
{
	std::cout << "const print: " << x << std::endl;
}

template <typename D>
void printX(D &x) 
{
	std::cout << "print: " << x << std::endl;
}

int main(void)
{
	int	 i_arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
	const size_t i_arr_len = 8;

	char c_arr[] = "12_Slices_of_Pizza!_:D";
	const size_t c_arr_len = 22;

	::iter(i_arr, i_arr_len, roundOddsUp);
	::iter(c_arr, c_arr_len, ftToUpper);

	for (int i = 0; i < 8; i++)
		std::cout << i_arr[i] << " ";
	std::cout << std::endl;
	std::cout << c_arr << std::endl;

	::iter(i_arr, i_arr_len, increment<int>);
	::iter(c_arr, c_arr_len, increment<char>);

	for (int i = 0; i < 8; i++)
		std::cout << i_arr[i] << " ";
	std::cout << std::endl;
	std::cout << c_arr << std::endl;

	::iter(i_arr, i_arr_len / 2, printX<int>);
	::iter(i_arr, i_arr_len / 2, printConstX<int>);
	::iter(c_arr, c_arr_len / 4, printX<char>);
	::iter(c_arr, c_arr_len / 4, printConstX<char>);
	return (0);
}

