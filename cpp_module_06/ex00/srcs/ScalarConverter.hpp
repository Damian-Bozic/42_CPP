/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:20:19 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/31 19:20:19 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <limits>
# include <cmath> 
# include <sstream>
# define	MAX_INT_CHAR_LENGTH 10
# define	MIN_INT_CHAR_LENGTH 11
# define	CHAR_LITERAL_CHAR_LENGTH 3
# define	POSITIVE_OVERFLOW_CHAR_LENGTH 18
# define	NEGATIVE_OVERFLOW_CHAR_LENGTH 19
# define	ASCII_TABLE_SIZE 127
# define	NON_SCIENTIFIC_NOTATION_MAX 999999

enum types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};
// The largest possible value floats will display without scientific notation (e)
// # define	NON_SCIENTIFIC_NOTATION_MIN 0.0001 // Unused, but good to keep on hand
class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter();
	// ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	virtual ~ScalarConverter() = 0;

	ScalarConverter &operator = (const ScalarConverter &other);

	static void convert(std::string literal); // print output
};


// static methods are methods that don't require an
//  instantiated object to be called.

#endif