/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:32:58 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 14:32:59 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data
{
	char c;
	int i;
	float f;
	double d;
};

class Serializer
{
	private:

	public:
	Serializer();
	// Serializer(void);
	Serializer(const Serializer &other);
	virtual ~Serializer() = 0;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer &operator = (const Serializer &other);
};

#endif
