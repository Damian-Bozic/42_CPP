/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:04:36 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 14:04:37 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 #define RPN_HPP
 #include <stack>
 #include <exception>
 #include <iostream>
 #define CHAR_TO_INT_DIFF 48
 #define INT_MAX 2147483647
 #define INT_MIN -2147483648

enum Operator {
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

class RPN
{
	private:
	std::stack<int> m_stack;

	public:
	RPN();
	// RPN(initialized);
	// RPN(copy);
	~RPN();

	RPN& operator=(const RPN& other);
	void PushElement(int);
	void Operate(Operator);
	void PrintSolution();

	class CalculationNotComplete : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class InvalidElement : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class NotEnoughElements : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class ElementOutOfBounds : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

class BadInput : public std::exception
{
	public:
		const char* what() const throw();
};

#endif