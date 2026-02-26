/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:26:02 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 16:26:04 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP
 #include <list>
 #include <vector>
 #include <deque>
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <sys/time.h>
 #define TESTSEQ {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7}
 #define TESTSTR "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"
class PmergeMe
{
	public:
		// VECTOR AND DEQUE
		enum sideIdentity {
			NON_PARTICIPATING,
			A = 'a',
			B = 'b'
		};

		//DEQUE
		struct dequeMember {
			std::deque<int>	sequence;
			enum sideIdentity	pairSide;
			size_t				pairNum;
			bool operator>(const dequeMember &other);
		};

		//VECTOR
		struct member {
			std::vector<int>	sequence;
			enum sideIdentity	pairSide;
			size_t				pairNum;
			bool operator>(const member &other);
		};

		// VECTOR AND DEQUE
		PmergeMe(std::string);
		~PmergeMe();

		//DEQUE
		void DequeDividePairs();
		void DequeinitAndInsert();
		void DequeinitMain();
		void DequeinsertPairs();
		void DequereInitSeq();
		void printDequeSeq();
		std::deque<int> DequeGetSequence() const;

		//VECTOR
		void DividePairs();
		void initAndInsert();
		void initMain();
		void insertPairs();
		void reInitSeq();
		void printVectSeq();
		std::vector<int> GetSequence() const;

	private:
		//DEQUE
		std::deque<int> m_dequeSeq;
		std::deque<dequeMember> m_dequePend;
		std::deque<dequeMember> m_dequeMain;
		size_t m_dequePairSize;

		//VECTOR
		std::vector<int> m_seq;
		std::vector<member> m_pend;
		std::vector<member> m_main;
		size_t m_pairSize; 
};

//VECTOR AND DEQUE
std::ostream& operator<<(std::ostream&, const std::vector<int>);
std::ostream& operator<<(std::ostream&, const PmergeMe);

//DEQUE
std::ostream& operator<<(std::ostream&, const std::deque<int>);
std::ostream& operator<<(std::ostream&, const std::deque<PmergeMe::dequeMember>);

//VECTOR
std::ostream& operator<<(std::ostream&, const std::vector<PmergeMe::member>);

#endif
