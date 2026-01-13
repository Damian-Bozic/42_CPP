/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:19:41 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/07 17:19:44 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

/* MAIN GIVEN IN THE SUBJECT */
// int main()
// {
// Span sp1 = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

int main()
{
	std::vector<unsigned int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	Span sp2 = Span(20000);
	try
	{
		for (unsigned int i = 0; i < 6; i++)
			sp2.addNumber((i % 42) * 42);
	}
	catch (std::exception &p)
	{
		std::cout << p.what() << std::endl;
	}
	Span sp3 = Span(1);
	sp3.addNumber(42);

	std::cout << "SP1 SP2 SP3 BEFORE TESTS" << std::endl;
	std::cout << sp1 << std::endl;
	std::cout << sp2 << std::endl;
	std::cout << sp3 << std::endl;
	std::cout << std::endl;

	std::cout << "SP1 shortest span and longest span" << std::endl;
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &p)
	{
		std::cout << p.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SP1 adding iterator range" << std::endl;
	try
	{
		sp1.addIteratorRange(vec.begin(), vec.end());
	}
	catch (std::exception &p)
	{
		std::cout << p.what() << std::endl;
	}
	std::cout << sp1 << std::endl;
	std::cout << std::endl;

	std::cout << "SP2 adding iterator range" << std::endl;
	try
	{
		sp2.addIteratorRange(vec.begin(), vec.end());
	}
	catch (std::exception &p)
	{
		std::cout << p.what() << std::endl;
	}
	std::cout << sp2 << std::endl;
	std::cout << std::endl;

	std::cout << "SP3 shortest span and longest span" << std::endl;
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &p)
	{
		std::cout << p.what() << std::endl;
	}
	return 0;
}