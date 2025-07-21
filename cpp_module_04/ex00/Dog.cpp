/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:29:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 16:58:51 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &Dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = Dog;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &Dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &Dog)
	{
		this->type = Dog.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}
