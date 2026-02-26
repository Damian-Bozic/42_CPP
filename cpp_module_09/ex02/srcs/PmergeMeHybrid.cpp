/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:26:00 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 16:26:00 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeHybrid.hpp"

// PmergeMe::PmergeMe()
// {

// }

PmergeMe::PmergeMe(std::string sequence) : m_pairSize(2)
{
	for (size_t i = 0; i < sequence.size(); i++) {
		m_seq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
		while (sequence[i] && sequence.at(i) != ' ')
			i++;
	}
	std::string jacobsthal(JACOBSTHAL);
	for (size_t i = 0; i < jacobsthal.size(); i++) {
		m_jacobsthal.push_back(atoi(jacobsthal.substr(i, jacobsthal.find_first_of(' ', i)).c_str()));
		while (jacobsthal[i] && jacobsthal.at(i) != ' ')
			i++;
	}
}

// PmergeMe::PmergeMe(PmergeMe &other)
// {

// }

PmergeMe::~PmergeMe()
{

}

// PmergeMe&
// PmergeMe::operator=(const PmergeMe& other)
// {

// }

void
PmergeMe::Sort()
{
	DividePairs();
	InitMainAndPend();
	InsertPairs();
}

/* A recursive function that sorts m_seq to the first stage of the Ford-Johnson algorithm */
void
PmergeMe::DividePairs()
{
	if (m_seq.size() < m_pairSize) {
		m_pairSize /= 2;
		return ;
	}
	std::vector<int> temp = m_seq;
	size_t leftCheckElement;
	size_t rightCheckElement;
	for (size_t i = 0; i < temp.size(); i += m_pairSize) {
		leftCheckElement = (m_pairSize / 2 - 1) + i;
		rightCheckElement = (m_pairSize - 1) + i;
		if (leftCheckElement >= temp.size() || rightCheckElement >= temp.size())
			break ;
		if (temp.at(leftCheckElement) > temp.at(rightCheckElement)) {
			for (size_t j = 0; j < m_pairSize / 2; j++) {
				m_seq.at(i + j) = temp.at(i + j + (m_pairSize / 2)); // left element
				m_seq.at(i + j + (m_pairSize / 2)) = temp.at(i + j); // right element
			}
		}
	}
	// std::cout << "pair size " << m_pairSize << std::endl;
	// std::cout << "sequence before = " << temp << std::endl;
	// std::cout << "sequence after  = " << m_seq << std::endl;
	m_pairSize *= 2;
	this->DividePairs();
}

/* Initialises m_main and m_pend based off m_seq. This is the second step in the Ford-Johnson algorithm */
void
PmergeMe::InitMainAndPend()
{
	element	elementForInsert;
	size_t	pairNum = 1;
	size_t	seq_pos = 0;

	m_pairSize /= 2;
	for (size_t i = 0; seq_pos + m_pairSize <= m_seq.size(); i++) {
		elementForInsert.pairNum = pairNum;
		if (i % 2) {
			elementForInsert.pairSide = A;
			pairNum++;
		}
		else
			elementForInsert.pairSide = B;
		for (size_t j = 0; j < m_pairSize; j++) {
			elementForInsert.sequence.push_back(m_seq.at(seq_pos + j));
		}
		m_main.push_back(elementForInsert);
		elementForInsert.sequence.clear();
		seq_pos += m_pairSize;
	}
	elementForInsert.pairNum = NON_PARTICIPATING;
	elementForInsert.pairSide = NON_PARTICIPATING;
	while (seq_pos < m_seq.size()) {
		elementForInsert.sequence.push_back(m_seq.at(seq_pos));
		seq_pos++;
	}
	m_main.push_back(elementForInsert);
	SplitMainAndPend();
}

/* seperates "b1, a1, a2, ax..., Leftovers" into m_main and "b2, b2, bx..." into m_pend */
void
PmergeMe::SplitMainAndPend()
{
	std::list<element> temp = m_main;
	std::list<element>::iterator tempIt = temp.begin();

	m_main.clear();
	m_pend.clear();
	m_main.push_back(*tempIt);
	while (tempIt != temp.end())
	{
		if (tempIt->pairSide == A)
			m_main.push_back(*tempIt);
		else if (tempIt->pairSide != A && tempIt->pairNum != 1)
			m_pend.push_back(*tempIt);
		tempIt++;
	}
	m_main.push_back(m_pend.back());
	m_pend.pop_back();
}

/* Clears m_seq (container<int>) then refills it with values from m_main (container<element>) */
void
PmergeMe::ReInitSeq()
{
	m_seq.clear();
	for (std::list<element>::iterator it = m_main.begin(); it != m_main.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_seq.push_back(it->sequence.at(i));
	m_main.clear();
	m_pend.clear();
}

// #include <unistd.h>
/* Returns an iterator to the next m_pend element to insert into m_main based off the jacobsthal sequence */
std::list<PmergeMe::element>::iterator
PmergeMe::FindPendElemToInsert()
{ // This could be made more efficient with static variables as it goes through the same search each time
	size_t i = 1;
	size_t j;
	std::list<element>::iterator pendIt;
	while (m_jacobsthal.at(i)) {
		j = m_jacobsthal[i] - m_jacobsthal[i - 1];
		for (size_t k = 0; k < j; k++) {
			pendIt = m_pend.begin();
			// std::cout << "looking for " << m_jacobsthal[i] - k << std::endl;
			// std::cout << "k" << k << std::endl;
			// sleep(1);
			while (pendIt != m_pend.end()) {
				// std::cout << "checking" << pendIt->pairNum << std::endl;
				if (pendIt->pairNum == m_jacobsthal[i] - k) {
					// std::cout << "FOUND" << std::endl;
					return (pendIt);
				}
				pendIt++;
			}
		}
		i++;
	}
	std::cout << "Error: Maximum Jacobsthal number reached" << std::endl;
	std::cout << "Error: Undefined behaviour expected" << std::endl;
	return (m_pend.begin());
}

/* A recursive function that inserts m_pend elements into m_main. Uses the Jacobsthal sequence. This is the third step in the Ford-Johnson Algorithm */
void
PmergeMe::InsertPairs()
{
	std::list<element>::iterator pendIt;
	std::list<element>::iterator mainIt;
	while (!m_pend.empty()) {
		pendIt = FindPendElemToInsert();
		mainIt = m_main.begin();
		while (mainIt != m_main.end() && mainIt->pairNum != pendIt->pairNum) {
			if (*mainIt > *pendIt)
				break;
			mainIt++;
		}
		m_main.insert(mainIt, *pendIt);
		m_pend.remove(*pendIt);
	}
	// std::cout << "AFTER SORTING" << std::endl;
	// std::cout << "m_main:\n" << m_main << std::endl;
	// std::cout << "m_pend:\n" << m_pend << std::endl;
	ReInitSeq();
	if (m_pairSize == 1)
		return ;
	InitMainAndPend();
	InsertPairs();
}

std::vector<int>
PmergeMe::GetSequence() const
{
	return (m_seq);
}

bool
PmergeMe::element::operator>(const element &other)
{
	return (this->sequence.back() > other.sequence.back());
}

bool
PmergeMe::element::operator==(const element &other)
{
	if (this->pairSide == other.pairSide && this->pairNum == other.pairNum)
		return (true);
	return (false);
}

std::ostream&
operator<<(std::ostream& os, const std::vector<int> vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		os << vect.at(i);
		if (i + 1 < vect.size())
			os << " ";
	}
	return (os);
}

std::ostream&
operator<<(std::ostream& os, const std::list<PmergeMe::element> list)
{
	std::list<PmergeMe::element>::const_iterator it = list.begin();

	if (list.empty()) {
		os << " empty";
		return (os);
	}
	for (size_t i = 0; i < list.size(); i++) {
		if (it->pairNum == 0)
			os << " leftover numbers:	" << it->sequence;
		else {
			os << " element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
			os << it->sequence;
		}
		it++;
		if (it != list.end())
			os << "\n";
	}
	return (os);
}

std::ostream&
operator<<(std::ostream& os, const PmergeMe sorter)
{
	os << sorter.GetSequence();
	return (os);
}
