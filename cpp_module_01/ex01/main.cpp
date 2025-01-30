/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:14:05 by dbozic            #+#    #+#             */
/*   Updated: 2025/01/15 16:14:06 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombies;
	int amount_of_zombies = 123456;
	int	i = 0;

	std::cout << "Amount of zombies expected in the horde " 
			<< amount_of_zombies << std::endl;

	zombies = zombieHorde(amount_of_zombies, "Dave");
	while (i < amount_of_zombies)
	{
		std::cout << "Zombie " << i + 1 << "	";
		zombies[i].announce();
		i++;
	}
	delete [](zombies);
	return (1);
}