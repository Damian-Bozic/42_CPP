/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:24:37 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/15 13:24:38 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP
 #include <string>
 #include <iostream>

class Zombie
{
	private:
		std::string m_name;

	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);
};

#endif
