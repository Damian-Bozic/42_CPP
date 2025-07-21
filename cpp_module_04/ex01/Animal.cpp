/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:29:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 16:58:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = Animal;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &Animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &Animal)
	{
		this->type = Animal.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "'Animal Noises'" << std::endl;
}
