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
	std::cout << "Dog default constructor called" << std::endl;
	type = "dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	brain = new Brain(*other.get_brain());
	// this->brain = other.brain;
	// this->brain->setThought(0, "cheese");
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete(brain);
		brain = new Brain(*other.get_brain());
	}
	return (*this);
}

Brain	*Dog::get_brain() const
{
	return (brain);
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}
