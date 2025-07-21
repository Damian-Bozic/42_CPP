/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:08:06 by dbozic            #+#    #+#             */
/*   Updated: 2025/06/05 12:08:07 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

// TODO fix non-const Animals

int main()
{
	std::cout << "\n---=== Make Array ===---\n" << std::endl;

	Animal *animals[4];
	animals[0] = new Cat();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Dog();
	animals[0]->makeSound();
	animals[2]->makeSound();

	std::cout << "\n---=== Deep Copy ===---\n" << std::endl;

	Cat* gregory = new Cat();
	std::cout << gregory->get_brain()->getThought(0) << std::endl;
	gregory->get_brain()->setThought(0, "Sometimes, I dream about a world of cheese..");
	std::cout << gregory->get_brain()->getThought(0) << std::endl;

	// OPTION A
/* 	std::cout << "\n---=== Copy Construct Start ===---\n" << std::endl;
	Cat* bob = new Cat(*gregory);
	std::cout << "\n---=== Copy Construct End ===---\n" << std::endl; */

	// OPTION B
	Cat* bob = new Cat();
	std::cout << "\n---=== Copy Assign Start ===---\n" << std::endl;
	*bob = *gregory;
	std::cout << "\n---=== Copy Assign End ===---\n" << std::endl;


	std::cout << "gregory: " << gregory << std::endl;
	std::cout << "gregorys brain: " << gregory->get_brain() << std::endl;
	std::cout << "gregorys thoughts: " << gregory->get_brain()->getThought(0) << std::endl;
	std::cout << "bob: " << bob << std::endl;
	std::cout << "bobs brain: " << bob->get_brain() << std::endl;
	std::cout << "bobs thoughts: " <<  bob->get_brain()->getThought(0) << std::endl;
	bob->get_brain()->setThought(0, "I wish I had cheese..");
	std::cout << "gregorys after thoughts: " << gregory->get_brain()->getThought(0) << std::endl;
	std::cout << "bobs after thoughts: " << bob->get_brain()->getThought(0) << std::endl;
	// All I dream of is cheese
	delete bob;
	delete gregory;

	std::cout << "\n---=== Delete Array ===---\n" << std::endl;

	int	i = 0;
	while (i < 4)
	{
		delete animals[i];
		i++;
	}
	std::cout << "\n---=== End of main ===---\n" << std::endl;
}

/* int main()
{
int	i = 0;

const Animal* j = new Dog();
const Animal* i = new Cat();

while (Animal[i] != NULL)

delete j;//should not create a leak
delete i;
return 0;
} */