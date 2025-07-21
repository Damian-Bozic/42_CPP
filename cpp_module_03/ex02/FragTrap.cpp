/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:10:56 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/19 14:27:20 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name;
	std::cout << " says: High five guys!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " throws rocks at " << target;
		std::cout << " causing " << attackDamage << " points of damage!\n";
		--energyPoints;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "A dead FragTrap named " << name << " tried to attack\n";
	}
	else
	{
		std::cout << "FragTrap " << name << " tried to attack";
		std::cout << " but it didn't have any energy" << std::endl;
	}
}

// void FragTrap::takeDamage(unsigned int amount)
// {
// 	if (hitPoints > 0 && (unsigned int) hitPoints > amount)
// 	{
// 		hitPoints -= amount;
// 		std::cout << "FragTrap " << name << " takes " << amount;
// 		std::cout << " damage, but is still alive with " << hitPoints
// 		<< " hp remaining" << std::endl;
// 	}
// 	else if (hitPoints > 0 && (unsigned int) hitPoints <= amount)
// 	{
// 		std::cout << "FragTrap " << name << " dies after taking " << amount;
// 		std::cout << " damage" << std::endl;
// 		hitPoints = 0;
// 	}
// 	else
// 	{
// 		std::cout << "FragTrap " << name << " gets hit, but is already dead\n";
// 	}
// }

// void FragTrap::beRepaired(unsigned int amount)
// {
// 	if (energyPoints > 0 && hitPoints > 0)
// 	{
// 		std::cout << "FragTrap " << name << " gets repaired by " << amount;
// 		hitPoints += amount;
// 		if (hitPoints > 100)
// 			hitPoints = 100;
// 		std::cout << " restoring him to " << hitPoints << " hit points!\n";
// 		--energyPoints;
// 	}
// 	else if (hitPoints <= 0)
// 	{
// 		std::cout << "A dead FragTrap named " << name << " tried to repair\n";
// 	}
// 	else
// 	{
// 		std::cout << "FragTrap " << name << " tried to repair";
// 		std::cout << " but it didn't have any energy" << std::endl;
// 	}
// }
