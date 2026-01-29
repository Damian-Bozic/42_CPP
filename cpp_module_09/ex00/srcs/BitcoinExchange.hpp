/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:27:10 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/27 20:27:11 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP
 #include <exception>
 #include <iostream>
 #include <map>
 #include <fstream>
 #include <string>
 #include <cstdlib>

 #define EXCHANGE_DATA_CSV "data.csv"
 #define YEAR_START 0
 #define YEAR_END 3
 #define MONTH_START 5
 #define MONTH_END 6
 #define DAY_START 8
 #define DAY_END 9
 #define RATE_VALUE_START 11
 #define N_OF_DAYS_IN_FOUR_YEARS 1461
 #define N_OF_DAYS_IN_REGULAR_YEAR 365

struct YearMonthDay
{
	int	year;
	int	month;
	int	day;
};

typedef std::map<YearMonthDay*, float> financeDataMap;
typedef std::pair<YearMonthDay*, float> financeDataPair;
class BitcoinExchange
{
	public:
		// BitcoinExchange();
		BitcoinExchange(std::string walletRecords);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);
		financeDataMap& ReadRateData(std::string fileName);
		double GetTotalTimeInDays(YearMonthDay);

	private:
		financeDataMap &m_rateData;
		financeDataMap &m_walletRecords;

	class NoSuchFile : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif

