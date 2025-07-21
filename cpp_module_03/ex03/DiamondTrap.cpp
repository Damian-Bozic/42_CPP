/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:35:20 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/19 14:35:21 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	// TODO fix
	// have every name start with its identifier
	// :name (parameter of the constructor + "_clap_name" suffix)
	(*this).name = name;
	hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap), name(diamondTrap.name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap asks itself am I " << name;
	std::cout << " or am I " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "DiamondTrap " << name << " shocks " << target;
		std::cout << " causing " << attackDamage << " points of damage!\n";
		--energyPoints;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "A dead DiamondTrap named " << name << " tried to attack\n";
	}
	else
	{
		std::cout << "DiamondTrap " << name << " tried to attack";
		std::cout << " but it didn't have any energy" << std::endl;
	}
}

// void DiamondTrap::takeDamage(unsigned int amount)
// {
// 	if (hitPoints > 0 && (unsigned int) hitPoints > amount)
// 	{
// 		hitPoints -= amount;
// 		std::cout << "DiamondTrap " << name << " takes " << amount;
// 		std::cout << " damage, but is still alive with " << hitPoints
// 		<< " hp remaining" << std::endl;
// 	}
// 	else if (hitPoints > 0 && (unsigned int) hitPoints <= amount)
// 	{
// 		std::cout << "DiamondTrap " << name << " dies after taking " << amount;
// 		std::cout << " damage" << std::endl;
// 		hitPoints = 0;
// 	}
// 	else
// 	{
// 		std::cout << "DiamondTrap " << name << " gets hit, but is already dead\n";
// 	}
// }

// void DiamondTrap::beRepaired(unsigned int amount)
// {
// 	if (energyPoints > 0 && hitPoints > 0)
// 	{
// 		std::cout << "DiamondTrap " << name << " gets repaired by " << amount;
// 		hitPoints += amount;
// 		if (hitPoints > 100)
// 			hitPoints = 100;
// 		std::cout << " restoring him to " << hitPoints << " hit points!\n";
// 		--energyPoints;
// 	}
// 	else if (hitPoints <= 0)
// 	{
// 		std::cout << "A dead DiamondTrap named " << name << " tried to repair\n";
// 	}
// 	else
// 	{
// 		std::cout << "DiamondTrap " << name << " tried to repair";
// 		std::cout << " but it didn't have any energy" << std::endl;
// 	}
// }
