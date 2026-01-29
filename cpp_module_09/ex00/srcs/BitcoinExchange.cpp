/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:27:07 by dbozic            #+#    #+#             */
/*   Updated: 2026/01/27 20:27:08 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* default constructor */
// BitcoinExchange::BitcoinExchange() : m_rateData(financeDataMap()), m_walletRecords(financeDataMap())
// {
// 	throw std::exception();
// }

/* argumented constructor */
BitcoinExchange::BitcoinExchange(std::string walletRecords) :
	m_rateData(ReadRateData(EXCHANGE_DATA_CSV)),
	m_walletRecords(ReadRateData(EXCHANGE_DATA_CSV))
{
	// m_rateData = ReadRateData(EXCHANGE_DATA_CSV);
	(void)walletRecords;
}

/* copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	m_rateData(other.m_rateData),
	m_walletRecords(other.m_walletRecords)
{
	//TODO
	*this = other;
}

/* deconstructor */
BitcoinExchange::~BitcoinExchange()
{
	delete &m_rateData;
	delete &m_walletRecords;
}

/* copy assignment constructor */
BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange& other)
{
	//TODO
	if (this == &other)
		return (*this);
	return (*this);
}

financeDataMap&
BitcoinExchange::ReadRateData(std::string fileName)
{
	std::ifstream infile(fileName.c_str());
	if (!infile.is_open())
		throw(NoSuchFile());
	
	std::string line;
	financeDataMap &rateData = *(new financeDataMap);
	YearMonthDay date = {0, 0, 0};
	while (getline(infile, line))
	{
		std::cout << "GETLINE" << line << std::endl;
		date.year = atoi(line.substr(YEAR_START, YEAR_END).c_str());
		date.month = atoi(line.substr(MONTH_START, MONTH_END).c_str());
		date.day = atoi(line.substr(DAY_START, DAY_END).c_str());
		rateData.insert(financeDataPair
			(&date, atof(line.substr(RATE_VALUE_START, line.size() - RATE_VALUE_START).c_str())));
	}
	infile.close();
	GetTotalTimeInDays(date);
	return (rateData);
}

static bool
IsLeapYear(YearMonthDay date)
{
	if (date.year % 4 == 0)
		return (true);
	return (false);
}

static short
GetMonthsInDays(YearMonthDay date)
{
	short months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short days = 0;
	if (IsLeapYear(date))
		months[1] = 29;
	for (short i = 0; i < date.month; i++)
		days += months[i];
	return (days);
}

static int
GetYearsInDays(YearMonthDay date)
{
	int	days = 0;
	short yearOffset = date.year % 4;
	days += (date.year / 4) * N_OF_DAYS_IN_FOUR_YEARS;
	days += (yearOffset * N_OF_DAYS_IN_REGULAR_YEAR);
	return (days);
}

double
BitcoinExchange::GetTotalTimeInDays(YearMonthDay date)
{
	double dateInDays = date.day;
	dateInDays += GetMonthsInDays(date);
	dateInDays += GetYearsInDays(date);
	return (dateInDays);
}

const char*
BitcoinExchange::NoSuchFile::what() const throw()
{
	return ("Bitcoin Exchange needed .csv file for exchange can't be found");
}

