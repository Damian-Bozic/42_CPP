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

PmergeMe::PmergeMe(std::string sequence) : m_vecPairSize(2), m_dequePairSize(2)
{
	for (size_t i = 0; i < sequence.size(); i++) {
		m_vecSeq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
		while (sequence[i] && sequence.at(i) != ' ')
			i++;
	}
	for (size_t i = 0; i < sequence.size(); i++) {
		m_dequeSeq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
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

// VVV DEQUE SECTION VVV

void
PmergeMe::DequeSort()
{
	DequeDividePairs();
	DequeInitMainAndPend();
	DequeInsertPairs();
}

/* A recursive function that sorts m_dequeSeq to the first stage of the Ford-Johnson algorithm */
void
PmergeMe::DequeDividePairs()
{
	if (m_dequeSeq.size() < m_dequePairSize) {
		m_dequePairSize /= 2;
		return ;
	}
	std::deque<int> temp = m_dequeSeq;
	size_t leftCheckElement;
	size_t rightCheckElement;
	for (size_t i = 0; i < temp.size(); i += m_dequePairSize) {
		leftCheckElement = (m_dequePairSize / 2 - 1) + i;
		rightCheckElement = (m_dequePairSize - 1) + i;
		if (leftCheckElement >= temp.size() || rightCheckElement >= temp.size())
			break ;
		if (temp.at(leftCheckElement) > temp.at(rightCheckElement)) {
			for (size_t j = 0; j < m_dequePairSize / 2; j++) {
				m_dequeSeq.at(i + j) = temp.at(i + j + (m_dequePairSize / 2)); // left element
				m_dequeSeq.at(i + j + (m_dequePairSize / 2)) = temp.at(i + j); // right element
			}
		}
	}
	// std::cout << "pair size " << m_dequePairSize << std::endl;
	// std::cout << "sequence before = " << temp << std::endl;
	// std::cout << "sequence after  = " << m_dequeSeq << std::endl;
	m_dequePairSize *= 2;
	this->DequeDividePairs();
}

/* Initialises m_dequeMain and m_dequePend based off m_dequeSeq. This is the second step in the Ford-Johnson algorithm */
void
PmergeMe::DequeInitMainAndPend()
{
	dequeElement	elementForInsert;
	size_t	pairNum = 1;
	size_t	seq_pos = 0;

	m_dequePairSize /= 2;
	for (size_t i = 0; seq_pos + m_dequePairSize <= m_dequeSeq.size(); i++) {
		elementForInsert.pairNum = pairNum;
		if (i % 2) {
			elementForInsert.pairSide = A;
			pairNum++;
		}
		else
			elementForInsert.pairSide = B;
		for (size_t j = 0; j < m_dequePairSize; j++) {
			elementForInsert.sequence.push_back(m_dequeSeq.at(seq_pos + j));
		}
		m_dequeMain.push_back(elementForInsert);
		elementForInsert.sequence.clear();
		seq_pos += m_dequePairSize;
	}
	elementForInsert.pairNum = NON_PARTICIPATING;
	elementForInsert.pairSide = NON_PARTICIPATING;
	while (seq_pos < m_dequeSeq.size()) {
		elementForInsert.sequence.push_back(m_dequeSeq.at(seq_pos));
		seq_pos++;
	}
	m_dequeMain.push_back(elementForInsert);
	DequeSplitMainAndPend();
}

/* seperates "b1, a1, a2, ax..., Leftovers" into m_dequeMain and "b2, b2, bx..." into m_dequePend */
void
PmergeMe::DequeSplitMainAndPend()
{
	std::deque<dequeElement> temp = m_dequeMain;
	std::deque<dequeElement>::iterator tempIt = temp.begin();

	m_dequeMain.clear();
	m_dequePend.clear();
	m_dequeMain.push_back(*tempIt);
	while (tempIt != temp.end())
	{
		if (tempIt->pairSide == A)
			m_dequeMain.push_back(*tempIt);
		else if (tempIt->pairSide != A && tempIt->pairNum != 1)
			m_dequePend.push_back(*tempIt);
		tempIt++;
	}
	m_dequeMain.push_back(m_dequePend.back());
	m_dequePend.pop_back();
}

/* Clears m_dequeSeq (container<int>) then refills it with values from m_dequeMain (container<dequeElement>) */
void
PmergeMe::DequeReInitSeq()
{
	m_dequeSeq.clear();
	for (std::deque<dequeElement>::iterator it = m_dequeMain.begin(); it != m_dequeMain.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_dequeSeq.push_back(it->sequence.at(i));
	m_dequeMain.clear();
	m_dequePend.clear();
}

// #include <unistd.h>
/* Returns an iterator to the next m_dequePend element to insert into m_dequeMain based off the jacobsthal sequence */
std::deque<PmergeMe::dequeElement>::iterator
PmergeMe::DequeFindPendElemToInsert()
{ // This could be made more efficient with static variables as it goes through the same search each time
	size_t i = 1;
	size_t j;
	std::deque<dequeElement>::iterator pendIt;
	while (m_jacobsthal.size() > i) {
		j = m_jacobsthal[i] - m_jacobsthal[i - 1];
		for (size_t k = 0; k < j; k++) {
			pendIt = m_dequePend.begin();
			// std::cout << "looking for " << m_jacobsthal[i] - k << std::endl;
			// std::cout << "k" << k << std::endl;
			// sleep(1);
			while (pendIt != m_dequePend.end()) {
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
	return (m_dequePend.begin());
}

/* A recursive function that inserts m_dequePend elements into m_dequeMain. Uses the Jacobsthal sequence. This is the third step in the Ford-Johnson Algorithm */
void
PmergeMe::DequeInsertPairs()
{
	std::deque<dequeElement>::iterator pendIt;
	std::deque<dequeElement>::iterator mainIt;
	while (!m_dequePend.empty()) {
		pendIt = DequeFindPendElemToInsert();
		mainIt = m_dequeMain.begin();
		while (mainIt != m_dequeMain.end() && mainIt->pairNum != pendIt->pairNum) {
			if (*mainIt > *pendIt)
				break;
			mainIt++;
		}
		m_dequeMain.insert(mainIt, *pendIt);
		m_dequePend.erase(pendIt);
	}
	// std::cout << "AFTER SORTING" << std::endl;
	// std::cout << "m_dequeMain:\n" << m_dequeMain << std::endl;
	// std::cout << "m_dequePend:\n" << m_dequePend << std::endl;
	DequeReInitSeq();
	if (m_dequePairSize == 1)
		return ;
	DequeInitMainAndPend();
	DequeInsertPairs();
}

std::deque<int>
PmergeMe::DequeGetSequence() const
{
	return (m_dequeSeq);
}

bool
PmergeMe::dequeElement::operator>(const dequeElement &other)
{
	if (this->pairSide == NON_PARTICIPATING)
		return (false);
	return (this->sequence.back() > other.sequence.back());
}

bool
PmergeMe::dequeElement::operator==(const dequeElement &other)
{
	if (this->pairSide == other.pairSide && this->pairNum == other.pairNum)
		return (true);
	return (false);
}

std::ostream&
operator<<(std::ostream& os, const std::deque<int> deque)
{
	for (size_t i = 0; i < deque.size(); i++)
	{
		os << deque.at(i);
		if (i + 1 < deque.size())
			os << " ";
	}
	return (os);
}

std::ostream&
operator<<(std::ostream& os, const std::deque<PmergeMe::dequeElement> deque)
{
	std::deque<PmergeMe::dequeElement>::const_iterator it = deque.begin();

	if (deque.empty()) {
		os << " empty";
		return (os);
	}
	for (size_t i = 0; i < deque.size(); i++) {
		if (it->pairNum == 0)
			os << " leftover numbers:	" << it->sequence;
		else {
			os << " Element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
			os << it->sequence;
		}
		it++;
		if (it != deque.end())
			os << "\n";
	}
	return (os);
}
