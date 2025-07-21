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

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap bob("Bob");
	ScavTrap greg(bob);
	ClapTrap *fred = new ScavTrap("Fred");

	greg.guardGate();
	fred->takeDamage(6);
	fred->attack("john");
	fred->takeDamage(1);
	fred->beRepaired(2);
	fred->beRepaired(9);
	fred->takeDamage(1);
	fred->attack("john");
	fred->beRepaired(2);
	fred->takeDamage(1);
	fred->takeDamage(2131);
	fred->beRepaired(12);
	fred->attack("john");
	delete fred;
}