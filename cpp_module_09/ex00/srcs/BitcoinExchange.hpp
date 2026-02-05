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

 #define EXCHANGE_DATA_CSV "srcs/data.csv"
 #define WALLET_DATA_TXT "srcs/input.txt"
 #define YEAR_START 0
 #define YEAR_END 3
 #define MONTH_START 5
 #define MONTH_END 6
 #define DAY_START 8
 #define DAY_END 9
 #define RATE_VALUE_START 11
 #define WALLET_VALUE_START 13
 #define N_OF_DAYS_IN_FOUR_YEARS 1461
 #define N_OF_DAYS_IN_REGULAR_YEAR 365

struct YearMonthDay
{
	int	year;
	int	month;
	int	day;

	double GetTotalTimeInDays() const;
	bool operator<(const YearMonthDay& other) const;
	bool operator==(const YearMonthDay& other) const;
}; // No way structs can have member functions 💀💀💀💀💀

typedef std::map<YearMonthDay, float> financeDataMap;
typedef std::pair<YearMonthDay, float> financeDataPair;
class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string walletRecords);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);
		financeDataMap* ReadRateData(std::string fileNameAndDir);
		financeDataMap* ReadWalletData(std::string fileNameAndDir);
		void PrintTrueWalletValue(void);

		class NoSuchCSVFile : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadCSVFileFormat : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class DuplicateCSVValue : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSuchWalletFile : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadWalletFileFormat : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadWalletValue : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class DuplicateWalletValue : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoPreviousEntry : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		financeDataMap *m_walletRecords;
		financeDataMap *m_rateData;
};

#endif

