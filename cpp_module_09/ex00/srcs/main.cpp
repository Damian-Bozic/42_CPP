/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:21:46 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/27 20:21:49 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "ERROR: Bad argument count" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc;
		btc.PrintWallet(argv[1]);
	}
	catch (const std::exception &e){
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
