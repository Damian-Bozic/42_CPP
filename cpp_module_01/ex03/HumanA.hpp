/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:23:22 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/17 18:23:22 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
 #define HUMANA_HPP
 #include <string>
 #include <iostream>
 #include "Weapon.hpp"

// we set the weapon as a reference here since it takes in a weapon only once
//  at init then it can have its type changed by setType();
class HumanA
{
	private:
		std::string	m_name;
		Weapon		&m_weapon;

	public:
		HumanA(const char *name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif
