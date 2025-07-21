/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:10:56 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/14 16:10:57 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = scavTrap;
	// if scavTrap had its on variables that needed copying then it would
	//  have to have its own assignment operator that does that
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name;
	std::cout << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << " causing " << attackDamage << " points of damage!\n";
		--energyPoints;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "A dead ScavTrap named " << name << " tried to attack\n";
	}
	else
	{
		std::cout << "ScavTrap " << name << " tried to attack";
		std::cout << " but it didn't have any energy" << std::endl;
	}
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
// 	if (hitPoints > 0 && (unsigned int) hitPoints > amount)
// 	{
// 		hitPoints -= amount;
// 		std::cout << "ScavTrap " << name << " takes " << amount;
// 		std::cout << " damage, but is still alive with " << hitPoints
// 		<< " hp remaining" << std::endl;
// 	}
// 	else if (hitPoints > 0 && (unsigned int) hitPoints <= amount)
// 	{
// 		std::cout << "ScavTrap " << name << " dies after taking " << amount;
// 		std::cout << " damage" << std::endl;
// 		hitPoints = 0;
// 	}
// 	else
// 	{
// 		std::cout << "ScavTrap " << name << " gets hit, but is already dead\n";
// 	}
// }

// void ScavTrap::beRepaired(unsigned int amount)
// {
// 	if (energyPoints > 0 && hitPoints > 0)
// 	{
// 		std::cout << "ScavTrap " << name << " gets repaired by " << amount;
// 		hitPoints += amount;
// 		if (hitPoints > 100)
// 			hitPoints = 100;
// 		std::cout << " restoring him to " << hitPoints << " hit points!\n";
// 		--energyPoints;
// 	}
// 	else if (hitPoints <= 0)
// 	{
// 		std::cout << "A dead ScavTrap named " << name << " tried to repair\n";
// 	}
// 	else
// 	{
// 		std::cout << "ScavTrap " << name << " tried to repair";
// 		std::cout << " but it didn't have any energy" << std::endl;
// 	}
// }
