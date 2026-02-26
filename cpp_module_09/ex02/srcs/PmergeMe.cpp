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

PmergeMe::PmergeMe(std::string sequence) : m_dequePairSize(2), m_pairSize(2)
{
	for (size_t i = 0; i < sequence.size(); i++) {
		m_dequeSeq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
		while (sequence[i] && sequence.at(i) != ' ')
			i++;
	}
	for (size_t i = 0; i < sequence.size(); i++) {
		m_seq.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
		while (sequence[i] && sequence.at(i) != ' ')
			i++;
	}
}

PmergeMe::~PmergeMe()
{
}

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
				m_dequeSeq.at(i + j) = temp.at(i + j + (m_dequePairSize / 2)); // left elements change
				m_dequeSeq.at(i + j + (m_dequePairSize / 2)) = temp.at(i + j); // right elements change
			}
		}
	}
	m_dequePairSize *= 2;
	this->DequeDividePairs();
}

void
PmergeMe::DequeinitAndInsert()
{
	std::cout << "startng deque init main" << std::endl;
	DequeinitMain();
	std::cout << "startng deque insert pairs" << std::endl;
	DequeinsertPairs();
}

void
PmergeMe::DequeinitMain()
{
	dequeMember	dequeMemberForInsert;
	size_t	pairNum = 1;
	size_t	seq_pos = 0;

	m_dequePairSize /= 2;
	for (size_t i = 0; seq_pos + m_dequePairSize <= m_dequeSeq.size(); i++) {
		dequeMemberForInsert.pairNum = pairNum;
		if (i % 2) {
			dequeMemberForInsert.pairSide = A;
			pairNum++;
		}
		else
			dequeMemberForInsert.pairSide = B;
		for (size_t j = 0; j < m_dequePairSize; j++) {
			dequeMemberForInsert.sequence.push_back(m_dequeSeq.at(seq_pos + j));
		}
		m_dequeMain.push_back(dequeMemberForInsert);
		dequeMemberForInsert.sequence.clear();
		seq_pos += m_dequePairSize;
	}
	dequeMemberForInsert.pairNum = 0;
	dequeMemberForInsert.pairSide = NON_PARTICIPATING;
	while (seq_pos < m_dequeSeq.size()) {
		dequeMemberForInsert.sequence.push_back(m_dequeSeq.at(seq_pos));
		seq_pos++;
	}
	m_dequeMain.push_back(dequeMemberForInsert);
}

void
PmergeMe::DequereInitSeq()
{
	m_dequeSeq.clear();
	for (std::deque<dequeMember>::iterator it = m_dequeMain.begin(); it != m_dequeMain.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_dequeSeq.push_back(it->sequence.at(i));
	m_dequeMain.clear();
	m_dequePend.clear();
}

void
PmergeMe::printDequeSeq()
{
	std::cout << m_dequeSeq << std::endl;
}

void
PmergeMe::DequeinsertPairs()
{
	std::deque<dequeMember> temp = m_dequeMain;
	std::deque<dequeMember>::iterator tempIt = temp.begin();

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
	std::cout << "m_main\n" << m_dequeMain << std::endl;
	std::cout << "m_pend\n" << m_dequePend << std::endl;
	while (!m_dequePend.empty())
	{ // Wobbly logic assumes that the ford johnson logic will always be true without actually counting the ford johnson numbers.
		while (!m_dequePend.empty()) {
			for (std::deque<dequeMember>::iterator mainIt = m_dequeMain.begin(); true; mainIt++) {
				if (*mainIt > m_dequePend.back()) {
					m_dequeMain.insert(mainIt, m_dequePend.back());
					m_dequePend.pop_back();
					break;
				}
			}
		}
		break;
	}
	DequereInitSeq();
	if (m_dequePairSize == 1)
		return ;
	DequeinitMain();
	DequeinsertPairs();
}

std::deque<int>
PmergeMe::DequeGetSequence() const
{
	return (m_dequeSeq);
}

bool
PmergeMe::dequeMember::operator>(const dequeMember &other)
{
	std::cout << "operator> deque start" << std::endl;
	std::cout << "comparing " << this->sequence.back()
		<< " to " << other.sequence.back() << std::endl;
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
operator<<(std::ostream& os, const std::deque<int> vect)
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
operator<<(std::ostream& os, const std::deque<PmergeMe::dequeMember> deque)
{
	std::deque<PmergeMe::dequeMember>::const_iterator it;

	it = deque.begin();
	for (size_t i = 0; i < deque.size(); i++)
	{
		if (it->pairNum == 0)
			os << "leftover numbers:	" << it->sequence;
		else {
			os << "element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
			os << it->sequence;
		}
		it++;
		if (it != deque.end())
			os << "\n";
	}
	return (os);
}

std::ostream&
operator<<(std::ostream& os, const PmergeMe sorter)
{
	os << "DEQUE: " << sorter.DequeGetSequence() << "\n";
	os << "VECT: " << sorter.GetSequence();
	return (os);
}

// START OF VECTOR AREA

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
	for (std::vector<member>::iterator it = m_main.begin(); it != m_main.end(); it++)
		for (size_t i = 0; i < it->sequence.size(); i++)
			m_seq.push_back(it->sequence.at(i));
	m_main.clear();
	m_pend.clear();
}

void
PmergeMe::insertPairs()
{
	std::vector<member> temp = m_main;
	std::vector<member>::iterator tempIt = temp.begin();

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
	while (!m_pend.empty())
	{ // Wobbly logic assumes that the ford johnson logic will always be true without actually counting the ford johnson numbers.
		while (!m_pend.empty()) {
			for (std::vector<member>::iterator mainIt = m_main.begin(); true; mainIt++) {
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
	if (m_pairSize == 1)
		return ;
	initMain();
	insertPairs();
}

void
PmergeMe::printVectSeq()
{
	std::cout << m_seq << std::endl;
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
operator<<(std::ostream& os, const std::vector<PmergeMe::member> vector)
{
	std::vector<PmergeMe::member>::const_iterator it;

	it = vector.begin();
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (it->pairNum == 0)
			os << "leftover numbers:	" << it->sequence;
		else {
			os << "element " << static_cast<char>(it->pairSide) << it->pairNum << " holds:	";
			os << it->sequence;
		}
		it++;
		if (it != vector.end())
			os << "\n";
	}
	return (os);
}
