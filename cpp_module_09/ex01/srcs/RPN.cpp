/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:04:31 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 14:04:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

// RPN::RPN(initialized)
// {
// }

// RPN::RPN(copy)
// {
// }

RPN::~RPN()
{
}

RPN&
RPN::operator=(const RPN& other)
{
	this->m_stack = other.m_stack;
	return (*this);
}

void
RPN::PushElement(int element)
{
	if (element > 9 || element < 0)
		throw(InvalidElement());
	m_stack.push(element);
}

void
RPN::Operate(Operator e)
{
	if (m_stack.size() < 2)
		throw(NotEnoughElements());
	long long elementB = m_stack.top();
	m_stack.pop();
	long long elementA = m_stack.top();
	m_stack.pop();
	switch (e) {
	case ADDITION:
		elementB = elementA + elementB;	
		break;
	case SUBTRACTION:
		elementB = elementA - elementB;
		break;
	case MULTIPLICATION:
		elementB = elementA * elementB;
		break;
	case DIVISION:
		elementB = elementA / elementB;
	}
	if (elementB > INT_MAX || elementB < INT_MIN)
		throw (ElementOutOfBounds());
	m_stack.push(static_cast<int>(elementB));
}

void
RPN::PrintSolution()
{
	if (m_stack.size() != 1)
		throw(CalculationNotComplete());
	std::cout << m_stack.top() << std::endl;
}

const char*
RPN::CalculationNotComplete::what() const throw()
{
	return ("Calculation is not completable");
}

const char*
RPN::InvalidElement::what() const throw()
{
	return ("Invalid element");
}

const char*
RPN::NotEnoughElements::what() const throw()
{
	return ("Not enough elements to complete an operation");
}

const char*
RPN::ElementOutOfBounds::what() const throw()
{
	return ("Element reached out of bounds");
}

const char*
BadInput::what() const throw()
{
	return ("Bad Input");
}

/* DEBUG VERSION */
// void
// RPN::Operate(Operator e)
// {
// 	if (m_stack.size() < 2)
// 		throw(NotEnoughElements());
// 	long long elementB = m_stack.top();
// 	m_stack.pop();
// 	long long elementA = m_stack.top();
// 	m_stack.pop();
// 	switch (e) {
// 	case ADDITION:
// 		std::cout << elementA << " + " <<elementB; elementB = elementA + elementB;	
// 		break;
// 	case SUBTRACTION:
// 		std::cout << elementA << " - " <<elementB; elementB = elementA - elementB;
// 		break;
// 	case MULTIPLICATION:
// 		std::cout << elementA << " * " <<elementB; elementB = elementA * elementB;
// 		break;
// 	case DIVISION:
// 		std::cout << elementA << " / " <<elementB; elementB = elementA / elementB;
// 	}
// 	std::cout << " = " << elementB << std::endl;
// 	if (elementB > INT_MAX || elementB < INT_MIN)
// 		throw (ElementOutOfBounds());
// 	m_stack.push(static_cast<int>(elementB));
// }