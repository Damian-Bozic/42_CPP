/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:41:11 by dbozic            #+#    #+#             */
/*   Updated: 2025/02/13 17:41:11 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP
 #include <iostream>
class ClapTrap
{
	protected:
		std::string name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		virtual ~ClapTrap();
		ClapTrap &operator = (const ClapTrap &clapTrap);
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		std::string	getName(void);
};


// BEFORE HAND IN TODO
// double check output messages

// Overriding can work without virtual, however if child is called through a
//  parent pointer, then it will show Claptrap and not Scavtrap
//  Remove virual and see what happens with the main provided
#endif
