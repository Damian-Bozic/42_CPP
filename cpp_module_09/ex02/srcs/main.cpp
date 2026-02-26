/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:52 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 16:25:52 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "ERROR: Bad argument count" << std::endl;
		return (1);
	}
	std::cout << "WARNING: If input contains non-digit characters or numbers outside int range expect undefined behaviour" << std::endl;
	struct timeval start;
	struct timeval stop;
	PmergeMe sorter(argv[1]);

	std::cout << "VECTOR" << std::endl;
	std::cout << "Unsorted vector: " <<	sorter.VectorGetSequence() << std::endl;;
	gettimeofday(&start, NULL);
	sorter.VectorSort();
	gettimeofday(&stop, NULL);
	std::cout << "Sorted vector: " << sorter.VectorGetSequence() << std::endl;;
	std::cout << "Time taken for vector in microseconds: " << stop.tv_usec - start.tv_usec << "us"<< std::endl;

	std::cout << "DEQUE" << std::endl;
	std::cout << "Unsorted deque: " << sorter.DequeGetSequence() << std::endl;;
	gettimeofday(&start, NULL);
	sorter.DequeSort();
	gettimeofday(&stop, NULL);
	std::cout << "Sorted deque: " << sorter.DequeGetSequence() << std::endl;;
	std::cout << "Time taken for deque in microseconds: " << stop.tv_usec - start.tv_usec << "us"<< std::endl;
}

// MAIN TO BE USED WITH OTHER FILES
// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	struct timeval start;
// 	struct timeval stop;

// 	PmergeMe sorter(TESTSTR);
// 	std::cout << "Unsorted: " << sorter << std::endl;
// 	gettimeofday(&start, NULL);
// 	sorter.DequeSort();
// 	gettimeofday(&stop, NULL);
// 	std::cout << "Sorted: " << sorter << std::endl;
// 	std::cout << "Time taken for PmergeMe in microseconds: " << stop.tv_usec - start.tv_usec << "us"<< std::endl;

// 	std::vector<int> vect;
// 	std::string sequence = TESTSTR;

// 	for (size_t i = 0; i < sequence.size(); i++) {
// 		vect.push_back(atoi(sequence.substr(i, sequence.find_first_of(' ', i)).c_str()));
// 		while (sequence[i] && sequence.at(i) != ' ')
// 			i++;
// 	}
// 	std::cout << "Unsorted: " << vect << std::endl;
// 	gettimeofday(&start, NULL);
// 	std::sort(vect.begin(), vect.end());
// 	gettimeofday(&stop, NULL);
// 	std::cout << "Sorted: " << vect << std::endl;
// 	std:: cout << "Time taken for std::sort on vector: " << stop.tv_usec - start.tv_usec << "us" << std::endl;
// }