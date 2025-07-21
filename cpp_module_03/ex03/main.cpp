/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:41:05 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/13 17:41:05 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap bob("Bob");
	// DiamondTrap greg(bob);
	// ClapTrap *fred = new FragTrap("Fred");
	// NOTE parent = new child // replcaes paretn functions with child functions
	// if parent is virtual

	bob.whoAmI();
	bob.guardGate();
	bob.highFivesGuys();
	// bob.guardGate();
	// bob.highFivesGuys();
	// bob.takeDamage(6);
	// bob.attack("john");
	// bob.takeDamage(1);
	// bob.beRepaired(2);
	// bob.beRepaired(9);
	// bob.takeDamage(1);
	// bob.attack("john");
	// bob.beRepaired(2);
	// bob.takeDamage(1);
	// bob.takeDamage(2131);
	// bob.beRepaired(12);
	// bob.attack("john");
	// delete fred;
}