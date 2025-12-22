/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:32:55 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 14:32:56 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* default constructor */
Serializer::Serializer()
{
}

/* argumented constructor */
// Serializer::Serializer(void)
// {
// }

/* copy constructor */
Serializer::Serializer(const Serializer &other)
{
	static_cast<void>(other);
}

/* copy assignment constructor */
Serializer &Serializer::operator = (const Serializer &other)
{
	static_cast<void>(other);
	return (*this);
}

/* deconstructor */
Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
