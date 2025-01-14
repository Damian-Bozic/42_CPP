/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:53:53 by dbozic            #+#    #+#             */
/*   Updated: 2024/12/20 14:53:54 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(int argc, char **argv)
{
	int	i;
	int	arg_no;

	arg_no = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while(argv[arg_no])
	{
		i = 0;
		while(argv[arg_no][i])
		{
			argv[arg_no][i] = to_upper(argv[arg_no][i]);
			i++;
		}
		std::cout << argv[arg_no];
		arg_no++;
	}
	std::cout << "\n";
	return (0);
}
