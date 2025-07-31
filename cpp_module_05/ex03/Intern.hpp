/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:48:00 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/23 17:48:01 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *makePPF(std::string target);
		AForm *makeRRF(std::string target);
		AForm *makeSCF(std::string target);

	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern &operator = (const Intern &other);
		AForm *makeForm(std::string name, std::string target);
};

std::ostream &operator << (std::ostream &os, const AForm &aForm);

#endif
