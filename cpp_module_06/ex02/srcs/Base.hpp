/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:06:54 by dbozic            #+#    #+#             */
/*   Updated: 2025/12/22 16:06:55 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	private:

	public:
		virtual ~Base();
		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

#endif
