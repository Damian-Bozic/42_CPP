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

YearMonthDay::YearMonthDay() : year(0), month(0), day(0)
{
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
	for (short i = 0; i < date.month - 1; i++)
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
YearMonthDay::GetTotalTimeInDays() const
{
	double dateInDays = this->day;
	dateInDays += GetMonthsInDays(*this);
	dateInDays += GetYearsInDays(*this);
	return (dateInDays);
}

bool
YearMonthDay::operator<(const YearMonthDay& other) const
{
	return (this->GetTotalTimeInDays() < other.GetTotalTimeInDays());
}

/* Unused in cpp09 */
bool
YearMonthDay::operator==(const YearMonthDay& other) const
{
	return (this->GetTotalTimeInDays() == other.GetTotalTimeInDays());
}

bool
YearMonthDay::valid() const
{
	short months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (this->year < 1)
		return (false);
	if (this->year % 4 == 0)
		months[1] = 29;
	if (this->month < 1 || this-> month > 12 ||
		this->day < 1 || this->day > months[month - 1])
		return (false);
	return (true);
}

// BITCOINEXCHANGE //

static YearMonthDay
ParseDate(std::string line)
{
	YearMonthDay date;
	if (line.size() < 10) {
		date.year = 0;
		date.month = 0;
		date.day = 0;
	}
	else {
		date.year = atoi(line.substr(YEAR_START, YEAR_END + 1).c_str());
		date.month = atoi(line.substr(MONTH_START , MONTH_END + 1).c_str());
		date.day = atoi(line.substr(DAY_START , DAY_END + 1).c_str());
	}
	return (date);
}

static bool
isValidFloatLiteral(std::string floatLiteral)
{
	bool floatDot = false;

	for (size_t i = 0; i < floatLiteral.size(); i++) {
		// std::cout << "checking:" << floatLiteral.at(i) << std::endl;
		if (!isdigit(floatLiteral.at(i))) {
			if (floatLiteral.at(i) == '.' && floatDot == false) {
				floatDot = true;
				continue ;
			}
			// std::cout << "INVALID FLOAT:" << floatLiteral << std::endl;
			return (false);
		}
	}
	return (true);
}

void
BitcoinExchange::ParseExchangeData(std::ifstream &recordFile)
{ // TODO have this throw on duplicates or any other errors
	std::string floatLiteral;
	std::string buffer;
	YearMonthDay date;
	bool firstLine = true;

	while (getline(recordFile, buffer)) {
		// std::cout << ":" << buffer << ":" << std::endl;
		if (firstLine) {
			firstLine = false;
			if (buffer != "date,exchange_rate")
				throw(BadRecordFileFormat());
			continue ;
		}
		if (buffer.size() < 12)
			throw(BadRecordFileFormat());
		if (buffer.at(4) != '-' || buffer.at(7) != '-' || buffer.at(10) != ',')
			throw(BadRecordFileFormat());
		else {
			floatLiteral = buffer.substr(RATE_VALUE_START, buffer.size() - RATE_VALUE_START).c_str();
			if (!isValidFloatLiteral(floatLiteral))
				throw(BadRecordFileFormat());
		}
		date = ParseDate(buffer);
		if (!date.valid())
			throw(BadRecordFileFormat());
		if (m_exchangeData->find(date) != m_exchangeData->end())
			throw(DuplicateRecordValue());
		m_exchangeData->insert(financeDataPair(date, atof(floatLiteral.c_str())));
	}
}

static void
PrintWalletValueLine(financeDataPair wallet, financeDataMap::iterator itRate)
{
	std::cout << wallet.first.year << "-"
	<< wallet.first.month << "-"
	<< wallet.first.day << " => "
	<< wallet.second * itRate->second << std::endl;
}

void
BitcoinExchange::PrintWallet(std::ifstream &walletFile)
{
	std::string floatLiteral;
	std::string buffer;
	financeDataPair currentPair;
	financeDataMap::iterator	itRate;
	bool firstLine = true;

	while (getline(walletFile, buffer)) {
		if (firstLine) {
			firstLine = false;
			if (buffer != "date | value")
				throw(BadWalletFileFormat());
			continue ;
		}
		try {
			if (buffer.size() < 14)
				throw(BadWalletEntryFileFormat());
			else 
				floatLiteral = buffer.substr(WALLET_VALUE_START, buffer.size() - WALLET_VALUE_START).c_str();
			if (!isValidFloatLiteral(floatLiteral)) {
				floatLiteral = "-1";
			}
			currentPair = financeDataPair(ParseDate(buffer), atof(floatLiteral.c_str()));
			
			//BUTCHERED CODE
			if (buffer.at(4) != '-' || buffer.at(7) != '-' || buffer.at(10) != ' '
				|| buffer.at(11) != '|' || buffer.at(12) != ' ')
					throw(BadWalletEntryFileFormat());
			if (!currentPair.first.valid() || currentPair.second == -1)
				throw (BadWalletEntryFileFormat());
			if (currentPair.second > 1000 || currentPair.second < 0)
				throw (BadWalletValue());
			itRate = m_exchangeData->begin();
			
			for (long unsigned int j = 0; j < m_exchangeData->size(); j++) {
				if (!itRate->first.valid() || itRate->second == -1) {
					throw (BadRecordFileFormat());
				}
				if (currentPair.first.GetTotalTimeInDays() == itRate->first.GetTotalTimeInDays()) {
					PrintWalletValueLine(currentPair, itRate);
					break;
				}
				else if (currentPair.first.GetTotalTimeInDays() < itRate->first.GetTotalTimeInDays()) {
					if (itRate == m_exchangeData->begin())
						throw(NoPreviousEntry());
					itRate--;
					PrintWalletValueLine(currentPair, itRate);
					break;
				}
				itRate++;
			}
		}
		catch(const std::exception& e) {
			std::cerr << "ERROR:" << e.what() << ":" << buffer << '\n';
		}
	}
}

/* argumented constructor */

BitcoinExchange::BitcoinExchange(std::string walletDataFileName) :
m_exchangeData(NULL)
{
	std::ifstream walletFile(walletDataFileName.c_str());
	std::ifstream recordFile((static_cast<std::string>(EXCHANGE_DATA_CSV)).c_str());

	if (!walletFile.is_open())
		throw(NoSuchWalletFile());
	if (!recordFile.is_open())
		throw(NoSuchRecordFile());
	m_exchangeData = (new financeDataMap());
	ParseExchangeData(recordFile);
	PrintWallet(walletFile);
}

/* copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
m_exchangeData(other.m_exchangeData)
{
	*this = other;
}

/* deconstructor */
BitcoinExchange::~BitcoinExchange()
{
	delete m_exchangeData;
}

/* copy assignment constructor */
BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	this->m_exchangeData = other.m_exchangeData;
	return (*this);
}

/* This could be made more efficient if we could be sure that the input was ordered from oldest to newst*/
// void BitcoinExchange::PrintWalletOnMarketPrice(void)
// {
// 	financeDataMap::iterator	itWallet = m_walletData->begin();
// 	financeDataMap::iterator	itRate;

// 	for (long unsigned int i = 0; i < m_walletData->size(); i++) {	
// 		try {
// 			if (!itWallet->first.valid() || itWallet->second == -1)
// 				throw (BadWalletEntryFileFormat());
// 			if (itWallet->second > 1000 || itWallet->second < 0)
// 				throw (BadWalletValue());
// 			itRate = m_exchangeData->begin();
// 			for (long unsigned int j = 0; j < m_exchangeData->size(); j++) {
// 				if (!itRate->first.valid() || itRate->second == -1) {
// 					throw (BadRecordFileFormat());
// 				}
// 				if (itWallet->first.GetTotalTimeInDays() == itRate->first.GetTotalTimeInDays()) {
// 					PrintWalletValueLine(itWallet, itRate);
// 					break;
// 				}
// 				else if (itWallet->first.GetTotalTimeInDays() < itRate->first.GetTotalTimeInDays()) {
// 					if (itRate == m_exchangeData->begin())
// 						throw(NoPreviousEntry());
// 					itRate--;
// 					PrintWalletValueLine(itWallet, itRate);
// 					break;
// 				}
// 				itRate++;
// 			}
// 		}
// 		catch (const std::exception &e) {
// 			std::cout << "ERROR:" << e.what() << std::endl;
// 		}
// 		itWallet++;
// 	}
// }

const char*
BitcoinExchange::NoSuchRecordFile::what() const throw()
{
	return ("No Bitcoin exchange rate file found");
}

const char*
BitcoinExchange::NoSuchWalletFile::what() const throw()
{
	return ("No input file found. Wallet balance(s) needed");
}

const char*
BitcoinExchange::BadRecordFileFormat::what() const throw()
{
	return ("Bitcoin exchange rate file bad format");
}

const char*
BitcoinExchange::DuplicateRecordValue::what() const throw()
{
	return ("Bitcoin rates file has duplicate dates");
}

const char*
BitcoinExchange::BadWalletFileFormat::what() const throw()
{
	return ("Bad wallet file header format. Should be \"date | value\"");
}

const char*
BitcoinExchange::BadWalletEntryFileFormat::what() const throw()
{
	return ("Bad wallet entry format");
}

const char*
BitcoinExchange::BadWalletValue::what() const throw()
{
	return ("Invalid Wallet Balance. Allowed 0 - 1000");
}

const char*
BitcoinExchange::DuplicateWalletValue::what() const throw()
{
	return ("Input file has duplicate dates");
}

const char*
BitcoinExchange::NoPreviousEntry::what() const throw()
{
	return ("No current or previous rate data found");
}
