/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:52 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 16:25:52 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	PmergeMe sorter(TESTSTR);
	std::cout << sorter << std::endl;
	sorter.DividePairs();
	std::cout << sorter << std::endl;
	sorter.initAndInsert();
	std::cout << sorter << std::endl;
}