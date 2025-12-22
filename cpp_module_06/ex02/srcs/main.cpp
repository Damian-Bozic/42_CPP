/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:09:01 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 16:09:02 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main (void)
{
	Base var;
	Base *ptr;

	ptr = var.generate();
	std::cout << "pointer identify: ";
	var.identify(ptr);
	std::cout << "reference identify: ";
	var.identify(*ptr);
	return (0);
}
