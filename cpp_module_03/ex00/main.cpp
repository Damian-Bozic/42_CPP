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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");

	bob.takeDamage(6);
	bob.takeDamage(1);
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.attack("john");
	bob.takeDamage(1);
	bob.beRepaired(2);
	bob.beRepaired(9);
	bob.takeDamage(1);
	bob.attack("john");
	bob.beRepaired(2);
	bob.takeDamage(1);
	bob.takeDamage(2131);
	bob.beRepaired(12);
	bob.attack("john");
}