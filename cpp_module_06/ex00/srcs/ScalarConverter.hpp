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
# define	CHAR 1
# define	INT 2
# define	FLOAT 3
# define	DOUBLE 4

class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter();
	// ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	virtual ~ScalarConverter() = 0;

	// ScalarConverter	operator=(const ScalarConverter &other);

	static void convert(std::string literal); // print output
};

// static methods are methods that don't require an
//  instantiated object to be called.

#endif