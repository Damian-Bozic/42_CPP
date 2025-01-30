/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:25:04 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/15 13:25:05 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// creates a zombie in stack memory, oppose to heap memory, as it only uses the
//  variables inside the scope of its own function.

void randomChump(std::string name)
{
	Zombie random_zombie(name);

	random_zombie.announce();
}
