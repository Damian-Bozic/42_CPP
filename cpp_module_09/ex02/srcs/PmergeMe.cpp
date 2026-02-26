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

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string sequence) : m_vecPairSize(2)
{
	for (size_t i = 0; i < sequence.size(); i++) {
		m_vecSeq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
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

PmergeMe::~PmergeMe()
{

}

void
PmergeMe::VectorSort()
{
	VectorDividePairs();
	VectorInitMainAndPend();
	VectorInsertPairs();
}

/* A recursive function that VectorSorts m_vecSeq to the first stage of the Ford-Johnson algorithm */
void
PmergeMe::VectorDividePairs()
{
	if (m_vecSeq.size() < m_vecPairSize) {
		m_vecPairSize /= 2;
		return ;
	}
	std::vector<int> temp = m_vecSeq;
	size_t leftCheckElement;
	size_t rightCheckElement;
	for (size_t i = 0; i < temp.size(); i += m_vecPairSize) {
		leftCheckElement = (m_vecPairSize / 2 - 1) + i;
		rightCheckElement = (m_vecPairSize - 1) + i;
		if (leftCheckElement >= temp.size() || rightCheckElement >= temp.size())
			break ;
		if (temp.at(leftCheckElement) > temp.at(rightCheckElement)) {
			for (size_t j = 0; j < m_vecPairSize / 2; j++) {
				m_vecSeq.at(i + j) = temp.at(i + j + (m_vecPairSize / 2)); // left element
				m_vecSeq.at(i + j + (m_vecPairSize / 2)) = temp.at(i + j); // right element
			}
		}
	}
	// std::cout << "pair size " << m_vecPairSize << std::endl;
	// std::cout << "sequence before = " << temp << std::endl;
	// std::cout << "sequence after  = " << m_vecSeq << std::endl;
	m_vecPairSize *= 2;
	this->VectorDividePairs();
}

/* Initialises m_vecMain and m_vecPend based off m_vecSeq. This is the second step in the Ford-Johnson algorithm */
void
PmergeMe::VectorInitMainAndPend()
{
	vectorElement	elementForInsert;
	size_t	pairNum = 1;
	size_t	seq_pos = 0;

	m_vecPairSize /= 2;
	for (size_t i = 0; seq_pos + m_vecPairSize <= m_vecSeq.size(); i++) {
		elementForInsert.pairNum = pairNum;
		if (i % 2) {
			elementForInsert.pairSide = A;
			pairNum++;
		}
		else
			elementForInsert.pairSide = B;
		for (size_t j = 0; j < m_vecPairSize; j++) {
			elementForInsert.sequence.push_back(m_vecSeq.at(seq_pos + j));
		}
		m_vecMain.push_back(elementForInsert);
		elementForInsert.sequence.clear();
		seq_pos += m_vecPairSize;
	}
	elementForInsert.pairNum = NON_PARTICIPATING;
	elementForInsert.pairSide = NON_PARTICIPATING;
	while (seq_pos < m_vecSeq.size()) {
		elementForInsert.sequence.push_back(m_vecSeq.at(seq_pos));
		seq_pos++;
	}
	m_vecMain.push_back(elementForInsert);
	VectorSplitMainAndPend();
}

/* seperates "b1, a1, a2, ax..., Leftovers" into m_vecMain and "b2, b2, bx..." into m_vecPend */
void
PmergeMe::VectorSplitMainAndPend()
{
	std::vector<vectorElement> temp = m_vecMain;
	std::vector<vectorElement>::iterator tempIt = temp.begin();

	m_vecMain.clear();
	m_vecPend.clear();
	m_vecMain.push_back(*tempIt);
	while (tempIt != temp.end())
	{
		if (tempIt->pairSide == A)
			m_vecMain.push_back(*tempIt);
		else if (tempIt->pairSide != A && tempIt->pairNum != 1)
			m_vecPend.push_back(*tempIt);
		tempIt++;
	}
	m_vecMain.push_back(m_vecPend.back());
	m_vecPend.pop_back();
}

/* Clears m_vecSeq (container<int>) then refills it with values from m_vecMain (container<vectorElement>) */
void
PmergeMe::VectorReInitSeq()
{
	m_vecSeq.clear();
	for (std::vector<vectorElement>::iterator it = m_vecMain.begin(); it != m_vecMain.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_vecSeq.push_back(it->sequence.at(i));
	m_vecMain.clear();
	m_vecPend.clear();
}

// #include <unistd.h>
/* Returns an iterator to the next m_vecPend element to insert into m_vecMain based off the jacobsthal sequence */
std::vector<PmergeMe::vectorElement>::iterator
PmergeMe::VectorFindPendElemToInsert()
{ // This could be made more efficient with static variables as it goes through the same search each time
	size_t i = 1;
	size_t j;
	std::vector<vectorElement>::iterator pendIt;
	while (m_jacobsthal.size() > i) {
		j = m_jacobsthal[i] - m_jacobsthal[i - 1];
		for (size_t k = 0; k < j; k++) {
			pendIt = m_vecPend.begin();
			// std::cout << "looking for " << m_jacobsthal[i] - k << std::endl;
			// std::cout << "k" << k << std::endl;
			// sleep(1);
			while (pendIt != m_vecPend.end()) {
				// std::cout << "checking" << pendIt->pairNum << std::endl;
				if (pendIt->pairNum == m_jacobsthal[i] - k) {
					return (pendIt);
				}
				pendIt++;
			}
		}
		i++;
	}
	std::cerr << "Error: Maximum Jacobsthal number reached" << std::endl;
	std::cerr << "Error: Undefined behaviour expected" << std::endl;
	return (m_vecPend.begin());
}

/* A recursive function that inserts m_vecPend Elements into m_vecMain. Uses the Jacobsthal sequence. This is the third step in the Ford-Johnson Algorithm */
void
PmergeMe::VectorInsertPairs()
{
	std::vector<vectorElement>::iterator pendIt;
	std::vector<vectorElement>::iterator mainIt;
	while (!m_vecPend.empty()) {
		pendIt = VectorFindPendElemToInsert();
		mainIt = m_vecMain.begin();
		while (mainIt != m_vecMain.end() && mainIt->pairNum != pendIt->pairNum) {
			if (*mainIt > *pendIt)
				break;
			mainIt++;
		}
		m_vecMain.insert(mainIt, *pendIt);
		m_vecPend.erase(pendIt);
	}
	// std::cout << "AFTER VectorSortING" << std::endl;
	// std::cout << "m_vecMain:\n" << m_vecMain << std::endl;
	// std::cout << "m_vecPend:\n" << m_vecPend << std::endl;
	VectorReInitSeq();
	if (m_vecPairSize == 1)
		return ;
	VectorInitMainAndPend();
	VectorInsertPairs();
}

std::vector<int>
PmergeMe::VectorGetSequence() const
{
	return (m_vecSeq);
}

bool
PmergeMe::vectorElement::operator>(const vectorElement &other)
{
	if (this->pairSide == NON_PARTICIPATING)
		return (false);
	return (this->sequence.back() > other.sequence.back());
}

bool
PmergeMe::vectorElement::operator==(const vectorElement &other)
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
operator<<(std::ostream& os, const std::vector<PmergeMe::vectorElement> vector)
{
	std::vector<PmergeMe::vectorElement>::const_iterator it = vector.begin();

	if (vector.empty()) {
		os << " empty";
		return (os);
	}
	for (size_t i = 0; i < vector.size(); i++) {
		if (it->pairNum == 0)
			os << " leftover numbers:	" << it->sequence;
		else {
			os << " element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
			os << it->sequence;
		}
		it++;
		if (it != vector.end())
			os << "\n";
	}
	return (os);
}

std::ostream&
operator<<(std::ostream& os, const PmergeMe VectorSorter)
{
	os << VectorSorter.VectorGetSequence();
	return (os);
}
