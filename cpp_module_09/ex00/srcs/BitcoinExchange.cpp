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

static bool
IsLeapYear(YearMonthDay date)
{
	if (date.year % 4 == 0)
		return (true);
	return (false);
}

short
GetMonthsInDays(YearMonthDay date)
{
	short months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short days = 0;
	if (IsLeapYear(date))
		months[1] = 29;
	for (short i = 0; i < date.month - 1; i++)
		days += months[i];
	return (days);
}

int
GetYearsInDays(YearMonthDay date)
{
	int	days = 0;
	short yearOffset = date.year % 4;
	days += (date.year / 4) * N_OF_DAYS_IN_FOUR_YEARS;
	days += (yearOffset * N_OF_DAYS_IN_REGULAR_YEAR);
	return (days);
}

double
YearMonthDay::GetTotalTimeInDays() const
{
	double dateInDays = this->day;
	dateInDays += GetMonthsInDays(*this);
	dateInDays += GetYearsInDays(*this);
	// std::cout << "totaltimeindays: " << dateInDays << std::endl;
	return (dateInDays);
}

bool
YearMonthDay::operator<(const YearMonthDay& other) const
{
	return (this->GetTotalTimeInDays() < other.GetTotalTimeInDays());
}

bool
YearMonthDay::operator==(const YearMonthDay& other) const
{
	std::cout << "op== called";
	return (this->GetTotalTimeInDays() == other.GetTotalTimeInDays());
}

/* default constructor */
BitcoinExchange::BitcoinExchange() :
	m_walletRecords(NULL),
	m_rateData(NULL)
{
	try
	{
		m_walletRecords = ReadWalletData(WALLET_DATA_TXT);
		m_rateData = ReadRateData(EXCHANGE_DATA_CSV);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw(std::exception());
	}
}

/* argumented constructor */
BitcoinExchange::BitcoinExchange(std::string walletRecords) :
	m_walletRecords(NULL),
	m_rateData(NULL)
{
	try
	{
		m_walletRecords = ReadWalletData(walletRecords);
		m_rateData = ReadRateData(EXCHANGE_DATA_CSV);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw(std::exception());
	}
}

/* copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	m_walletRecords(other.m_walletRecords),
	m_rateData(other.m_rateData)
{
	*this = other;
}

/* deconstructor */
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "DECONSTRUCTOR" << std::endl;
	delete m_rateData;
	delete m_walletRecords;
}

/* copy assignment constructor */
BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange& other)
{
	//TODO
	if (this == &other)
		return (*this);
	this->m_rateData = other.m_rateData;
	this->m_walletRecords = other.m_walletRecords;
	return (*this);
}

static YearMonthDay
parseDate(std::string line)
{
	YearMonthDay date;
	date.year = atoi(line.substr(YEAR_START, YEAR_END + 1).c_str());
	date.month = atoi(line.substr(MONTH_START , MONTH_END + 1).c_str());
	date.day = atoi(line.substr(DAY_START , DAY_END + 1).c_str());
	return (date);
}

/* This is by far not a perfect checker, but it is expandable */
static bool
checkWalletFormat(std::string line)
{
	static bool firstLine = true;

	if (firstLine == true)
	{
		if (line == "date | value")
			firstLine = false;
		else
			throw(BitcoinExchange::BadWalletFileFormat());
		return (true);
	}
	if (line.size() < 14)
		throw(BitcoinExchange::BadWalletFileFormat());
	int i = line.find_first_of('|');
	if (i != 11)
		throw(BitcoinExchange::BadWalletFileFormat());
	return (false);
}

/* This is by far not a perfect checker, but it is expandable */
static bool
checkRateFormat(std::string line)
{
	static bool firstLine = true;

	if (firstLine == true)
	{
		if (line == "date,exchange_rate")
			firstLine = false;
		else
			throw(BitcoinExchange::BadCSVFileFormat());
		return (true);
	}
	if (line.size() < 12)
		throw(BitcoinExchange::BadCSVFileFormat());
	int i = line.find_first_of(',');
	if (i != 10)
		throw(BitcoinExchange::BadCSVFileFormat());
	return (false);
}

financeDataMap*
BitcoinExchange::ReadWalletData(std::string fileNameAndDir)
{
	std::ifstream infile(fileNameAndDir.c_str());
	if (!infile.is_open())
		throw(NoSuchWalletFile());

	financeDataMap*	walletData = (new financeDataMap());
	YearMonthDay	date;
	std::string		line;
	float			value;
	while (getline(infile, line))
	{
		if (checkWalletFormat(line))
			continue ;
		date = parseDate(line);
		if (walletData->find(date) != walletData->end())
			throw(DuplicateWalletValue());
		value = atof(line.substr(RATE_VALUE_START,line.size() - RATE_VALUE_START).c_str());
		if (value < 0 || value > 1000)
			throw(BadWalletValue());
		walletData->insert(financeDataPair(date, value));
	}
	infile.close();
	return (walletData);
}

financeDataMap*
BitcoinExchange::ReadRateData(std::string fileNameAndDir)
{
	std::ifstream infile(fileNameAndDir.c_str());
	if (!infile.is_open())
		throw(NoSuchCSVFile());

	financeDataMap*	rateData = (new financeDataMap);
	YearMonthDay	date;
	std::string		line;
	float			value;
	while (getline(infile, line))
	{
		if (checkRateFormat(line))
			continue ;
		date = parseDate(line);
		if (rateData->find(date) != rateData->end())
			throw(DuplicateCSVValue());
		value = atof(line.substr(RATE_VALUE_START,line.size() - RATE_VALUE_START).c_str());
		rateData->insert(financeDataPair(date, value));
	}
	infile.close();
	return (rateData);
}

void BitcoinExchange::PrintTrueWalletValue(void)
{
	financeDataMap::iterator	itWallet;
	financeDataMap::iterator	itRate;
	YearMonthDay				date;

	itWallet = m_walletRecords->begin();
	for (long unsigned int i = 0; i < m_walletRecords->size(); i++)
	{	
		date = itWallet->first;
		itRate = m_rateData->find(date);
		if (itRate == m_rateData->end())
		{
			std::cout << "NON-PERFECT DATE" << std::endl;
			// FIND CLOSEST DATE;
		}
		else
		{
			std::cout << itWallet->first.year << "-"
				<< itWallet->first.month << "-"
				<< itWallet->first.day << " => "
				<< itWallet->second * itRate->second << std::endl;
		}
	}
}

const char*
BitcoinExchange::NoSuchCSVFile::what() const throw()
{
	return ("No CSV file found\nBitcoin rate data needed");
}

const char*
BitcoinExchange::NoSuchWalletFile::what() const throw()
{
	return ("No input file found\nWallet balance(s) needed");
}

const char*
BitcoinExchange::BadCSVFileFormat::what() const throw()
{
	return ("Poorly formatted CSV file");
}

const char*
BitcoinExchange::DuplicateCSVValue::what() const throw()
{
	return ("CSV file has duplicate dates");
}

const char*
BitcoinExchange::BadWalletFileFormat::what() const throw()
{
	return ("Poorly formatted input file");
}

const char*
BitcoinExchange::BadWalletValue::what() const throw()
{
	return ("Invalid Wallet Balance");
}

const char*
BitcoinExchange::DuplicateWalletValue::what() const throw()
{
	return ("Input file has duplicate dates");
}

