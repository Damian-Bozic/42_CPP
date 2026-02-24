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
				m_seq.at(i + j) = temp.at(i + j + (m_pairSize / 2)); // left elements change
				m_seq.at(i + j + (m_pairSize / 2)) = temp.at(i + j); // right elements change
			}
		}
	}
	// std::cout << "pair size " << m_pairSize << std::endl;
	// std::cout << "sequence before = " << temp << std::endl;
	// std::cout << "sequence after  = " << m_seq << std::endl;
	m_pairSize *= 2;
	this->DividePairs();
}

void
PmergeMe::initAndInsert()
{
	initMain();
	insertPairs();
}

void
PmergeMe::initMain()
{
	member	memberForInsert;
	size_t	pairNum = 1;
	size_t	seq_pos = 0;

	m_pairSize /= 2;
	for (size_t i = 0; seq_pos + m_pairSize <= m_seq.size(); i++) {
		memberForInsert.pairNum = pairNum;
		if (i % 2) {
			memberForInsert.pairSide = A;
			pairNum++;
		}
		else
			memberForInsert.pairSide = B;
		for (size_t j = 0; j < m_pairSize; j++) {
			memberForInsert.sequence.push_back(m_seq.at(seq_pos + j));
		}
		m_main.push_back(memberForInsert);
		memberForInsert.sequence.clear();
		seq_pos += m_pairSize;
	}
	memberForInsert.pairNum = 0;
	memberForInsert.pairSide = NON_PARTICIPATING;
	while (seq_pos < m_seq.size()) {
		memberForInsert.sequence.push_back(m_seq.at(seq_pos));
		seq_pos++;
	}
	m_main.push_back(memberForInsert);
}

void
PmergeMe::reInitSeq()
{
	m_seq.clear();
	for (std::list<member>::iterator it = m_main.begin(); it != m_main.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_seq.push_back(it->sequence.at(i));
	m_main.clear();
	m_pend.clear();
}

void
PmergeMe::insertPairs()
{
	std::list<member> temp = m_main;
	std::list<member>::iterator tempIt = temp.begin();

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
	// std::cout << "m_main\n" << m_main << std::endl;
	// std::cout << "m_pend\n" << m_pend << std::endl;
	// return pend leftover to main
	m_main.push_back(m_pend.back());
	m_pend.pop_back();
	while (!m_pend.empty())
	{ // Wobbly logic assumes that the ford johnson logic will always be true without actually counting the ford johnson numbers.
		while (!m_pend.empty()) {
			for (std::list<member>::iterator mainIt = m_main.begin(); true; mainIt++) {
				if (*mainIt > m_pend.back()) {
					m_main.insert(mainIt, m_pend.back());
					m_pend.pop_back();
					break;
				}
			}
		}
		break;
	}
	reInitSeq();
	// std::cout << *this << std::endl;
	if (m_pairSize == 1)
		return ;
	initMain();
	insertPairs();
}

std::vector<int>
PmergeMe::GetSequence() const
{
	return (m_seq);
}

bool
PmergeMe::member::operator>(const member &other)
{
	return (this->sequence.back() > other.sequence.back());
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
operator<<(std::ostream& os, const std::list<PmergeMe::member> list)
{
	std::list<PmergeMe::member>::const_iterator it;

	it = list.begin();
	for (size_t i = 0; i < list.size(); i++)
	{
		if (it->pairNum == 0)
			os << "leftover numbers:	" << it->sequence;
		else {
			os << "element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
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