/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:23:02 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/17 16:23:02 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "string.h"
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &Form);
		~ShrubberyCreationForm();
		std::string getTarget(void) const;
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &form);
		void execute(void) const;
};

std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm);

#endif
