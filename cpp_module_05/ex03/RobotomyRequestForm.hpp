/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:43:04 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/22 16:43:05 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "string.h"
# include <exception>
# include <fstream>
# include <stdlib.h>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <sys/time.h>


class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string		target;
		// unsigned int	randSeed;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &Form);
		~RobotomyRequestForm();
		std::string getTarget(void) const;
		RobotomyRequestForm &operator = (const RobotomyRequestForm &form);
		void execute(void) const;
};

std::ostream &operator << (std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm);

#endif
