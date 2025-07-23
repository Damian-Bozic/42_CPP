/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:42:55 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/22 16:42:56 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
 AForm("Robotomy Creation Form", 72, 45), target("Unknown Target")
{
	std::cout << "Robotomy Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
 AForm("Robotomy Creation Form", 72, 45), target(target)
{
	std::cout << "Robotomy Form parameterized built constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
 AForm("Robotomy Creation Form", 72, 45)
{
	std::cout << "Robotomy Form copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Form deconstructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
	std::cout << "Robotomy Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setSignatureStatus(other.getSignatureStatus());
		this->target = other.getTarget();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const RobotomyRequestForm &robotomyRequestForm)
{
	return (os
	 << "Form \"" << robotomyRequestForm.getName()
	 << "\", sign grade: "
	 << robotomyRequestForm.getSignGrade()
	 << ", exec grade: " << robotomyRequestForm.getExecGrade()
	 << ", target: " << robotomyRequestForm.getTarget()
	 << ", is signed: " << robotomyRequestForm.getSignatureStatus());
}

/* void RobotomyRequestForm::execute(void) const
{
	static double i = 1;
	std::cout << time(0) << std::endl;
	std::cout << "Robotomy exec called" << std::endl;
	srand((double)time(0) - i);
	i++;
	// int random = rand_r(&randSeed);
	int random = rand();
	std::cout << "RANDOM NUMBER WAS " << random << std::endl;
	if (random % 2 == 0)
	{
		std::cout << getTarget() << "'s robotomy succeeded." << std::endl;
	}
	else
	{
		std::cout << getTarget() << "'s robotomy failed." << std::endl;
	}
	//TODO Finish this
} */

void RobotomyRequestForm::execute(void) const
{
	static int i = 0;
    struct timeval tp;

    // std::cout << "Robotomy exec called" << std::endl;
    gettimeofday(&tp, NULL);
    long long mslong = (long long) tp.tv_sec * 1000L + tp.tv_usec + i;
	i++;
    srand(mslong);
    int random = rand();
    // std::cout << "RANDOM NUMBER WAS " << random << std::endl;
    if (random % 2 == 0)
    {
        std::cout << getTarget() << "'s robotomy succeeded" << std::endl;
    }
    else
    {
        std::cout << getTarget() << "'s robotomy failed" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}
