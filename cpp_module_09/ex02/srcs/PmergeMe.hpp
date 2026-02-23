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
 #include <vector>
 #include <list>
 #include <deque>
 #include <string>
 #include <iostream>
 #include <cstdlib>
 #define TESTSEQ {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7}
 #define TESTSTR "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"
class PmergeMe
{


	public:
		// PmergeMe();
		PmergeMe(std::string);
		// PmergeMe(PmergeMe &other);
		~PmergeMe();
		// PmergeMe& operator=(const PmergeMe& other);

		void DividePairs();
		void initAndInsert();
		void initMain();
		void insertPairs();
		std::vector<int> GetSequence() const;

		enum sideIdentity {
			NON_PARTICIPATING,
			A = 'a',
			B = 'b'
		};

		struct member {
			std::vector<int>	sequence;
			enum sideIdentity	pairSide;
			size_t				pairNum;
		};

	private:
		std::vector<int> m_seq;
		std::list<member> m_pend;
		std::list<member> m_main;
		size_t m_pairSize; 
};

std::ostream& operator<<(std::ostream&, const std::vector<int>);
std::ostream& operator<<(std::ostream&, const std::list<PmergeMe::member>);
std::ostream& operator<<(std::ostream&, const PmergeMe);

#endif
