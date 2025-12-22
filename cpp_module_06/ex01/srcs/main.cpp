/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:53:40 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 14:53:42 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data sending_data;
	uintptr_t serialized_pointer;
	Data *pointer_to_data;

	sending_data.c = 'c';
	sending_data.i = 1;
	sending_data.f = 1.23f;
	sending_data.d = 2.46;
	serialized_pointer = Serializer::serialize(&sending_data);
	pointer_to_data = Serializer::deserialize(serialized_pointer);
	std::cout << pointer_to_data->c << " "
		<< pointer_to_data->i << " " 
		<< pointer_to_data->f << " "
		<< pointer_to_data->d << " " << std::endl;
	return (0);
}
