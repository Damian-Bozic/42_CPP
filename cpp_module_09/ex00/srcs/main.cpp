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

// void initRateData(std::string csv_filename, struct tm *rate_data)
// {
// 	return ;
// }

// void initWalletRecords(std::string input_filename, struct tm *wallet_records)
// {
// 	return ;
// }

// void printWalletAtExchangedRate(std::map<struct tm *, float> rate_data,
// 	std::map<struct tm *, float> wallet_records)
// {

// }

int main(void)
{
	try
	{
		BitcoinExchange test;
		test.PrintTrueWalletValue();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
