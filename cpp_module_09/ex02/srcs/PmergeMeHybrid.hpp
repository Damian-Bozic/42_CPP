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

#ifndef PMERGEMEHYBRID_HPP
 #define PMERGEMEHYBRID_HPP
 #include <vector>
 #include <list>
 #include <deque>
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #include <sys/time.h>
 #define TESTSEQ {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7}
 #define TESTSTR "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"
 #define JACOBSTHAL "1 3 5 11 21 43 85 171 341 683 1365 2731 5461 10923 21845 43691 87381 174763 349525 699051 1398101 2796203 5592405 11184811 22369621 44739243 89478485 178956971 357913941 715827883 1431655765"
class PmergeMe
{
	public:
		enum sideIdentity {
			NON_PARTICIPATING,
			A = 'a',
			B = 'b'
		};

		struct element {
			std::vector<int>	sequence;
			enum sideIdentity	pairSide;
			size_t				pairNum;
			bool operator>(const element &other);
			bool operator==(const element &other);
		};

		// PmergeMe();
		PmergeMe(std::string);
		// PmergeMe(PmergeMe &other);
		~PmergeMe();
		// PmergeMe& operator=(const PmergeMe& other);

		void Sort();
		void DividePairs();
		void InitMainAndPend();
		void SplitMainAndPend();
		std::list<element>::iterator FindPendElemToInsert();
		void InsertPairs();
		void ReInitSeq();
		std::vector<int> GetSequence() const;

	private:
		std::vector<int> m_seq;
		std::vector<int> m_jacobsthal;
		std::list<element> m_pend;
		std::list<element> m_main;
		size_t m_pairSize; 
};

std::ostream& operator<<(std::ostream&, const std::vector<int>);
std::ostream& operator<<(std::ostream&, const std::list<PmergeMe::element>);
std::ostream& operator<<(std::ostream&, const PmergeMe);

#endif
