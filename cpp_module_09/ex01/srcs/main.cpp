/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:04:25 by dbozic            #+#    #+#             */
/*   Updated: 2026/02/09 14:04:26 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool
IsOdd(unsigned int i) {
	return (i % 2);
}

static void
ExecChar(char currentChar, RPN &rpn)
{
	if (isdigit(currentChar))
		rpn.PushElement((currentChar - CHAR_TO_INT_DIFF));
	else {
		switch (currentChar)
		{
		case '+':
			rpn.Operate(ADDITION);
			break;
		case '-':
			rpn.Operate(SUBTRACTION);
			break;
		case '*':
			rpn.Operate(MULTIPLICATION);
			break;
		case '/':
			rpn.Operate(DIVISION);
			break;
		default:
			throw(BadInput());
		}
	}
}

int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw(BadInput());
		std::string line = argv[1];
		char currentChar;
		RPN stackCalculator;
		for (size_t pos = 0; pos < line.size(); pos++) {
			currentChar = line.at(pos);
			if (IsOdd(static_cast<int>(pos)) && currentChar != ' ')
				throw(BadInput());
			else if (!IsOdd(static_cast<int>(pos)))
				ExecChar(currentChar, stackCalculator);
		}
		stackCalculator.PrintSolution();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

/* IsOdd Tester*/
// int main (void)
// {
// 	int i[11] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};

// 	for (int j = 0; j < 10; j++)
// 	{
// 		if (IsOdd(i[j]))
// 			std::cout << i[j] << " is odd" << std::endl;
// 		else
// 			std::cout << i[j] << " is even" << std::endl;
// 	}
// }