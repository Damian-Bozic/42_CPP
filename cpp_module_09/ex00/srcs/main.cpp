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

int
GetYearsInDays(YearMonthDay date);

short
GetMonthsInDays(YearMonthDay date);

int main(void)
{
	BitcoinExchange test;
	test.PrintTrueWalletValue();
	return (0);
	// YearMonthDay a = {2009, 1, 29};
	// YearMonthDay b = {2009, 2, 1};
	// std::cout << a.GetTotalTimeInDays() << std::endl;
	// std::cout << b.GetTotalTimeInDays() << std::endl; 

	// std::cout << a.day << std::endl;
	// std::cout << b.day << std::endl; 

	// std::cout << GetMonthsInDays(a) << std::endl;
	// std::cout << GetMonthsInDays(b) << std::endl; 

	// std::cout << GetYearsInDays(a) << std::endl;
	// std::cout << GetYearsInDays(b) << std::endl; 
}
