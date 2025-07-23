/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:57 by dbozic            #+#    #+#             */
/*   Updated: 2025/07/17 16:22:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
 AForm("Shrubbery Creation Form", 145, 137), target("Unknown Target")
{
	std::cout << "Shrub Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
 AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "Shrub Form parameterized built constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
 AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "Shrub Form copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrub Form deconstructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	std::cout << "Shrub Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setSignatureStatus(other.getSignatureStatus());
		this->target = other.getTarget();
	}
	return (*this);
}

std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	return (os
	 << "Form \"" << shrubberyCreationForm.getName()
	 << "\", sign grade: "
	 << shrubberyCreationForm.getSignGrade()
	 << ", exec grade: " << shrubberyCreationForm.getExecGrade()
	 << ", target: " << shrubberyCreationForm.getTarget()
	 << ", is signed: " << shrubberyCreationForm.getSignatureStatus());
}

void ShrubberyCreationForm::execute(void) const
{
	std::cout << "Shrub exec called" << std::endl;
	std::ofstream outputFile(getTarget().append("_shrubbery").c_str());
	if (outputFile.is_open())
	{
		outputFile << "                               Z111Z                            \n";
		outputFile << "                               Z111Z                            \n";
		outputFile << "                               Z111Z                            \n";
		outputFile << "                               Z111Z                            \n";
		outputFile << "                            111YUTTT           11111            \n";
		outputFile << "                            111XQOOO           11111            \n";
		outputFile << "                            111XQOOO           11111OOON        \n";
		outputFile << "                            111XQOOO           11111OOOOO       \n";
		outputFile << "            11111111Z       111YTSSSNNNNNNNQX1111111OOONO       \n";
		outputFile << "            111111111       1111111ZOOOOOOOQX1111111            \n";
		outputFile << "            111111111       1111111ZOOOOOOOQX1111111            \n";
		outputFile << "               OOOOPX111       Z11111111111XQOOOOOOO11111       \n";
		outputFile << "               OOOOPX111       Z11111111111XQOOOOOOO11111       \n";
		outputFile << "                   OOOOO1111POOQX11ZOOOOOOOON  NOOOO            \n";
		outputFile << "                   OOOOO1111POOQX11ZOOOOOOOON  NOOOO            \n";
		outputFile << "                    OOOORRRRVWWVSRRROOOOOOON    OOOO            \n";
		outputFile << "                        OOOOY11XQOOOOOOO                        \n";
		outputFile << "                   Z1111UUUUZ11XQOOOOOOO   MOOOO                \n";
		outputFile << "                   111111111111XQOOO       NOOOO                \n";
		outputFile << "   1Z1111111111111111111XXXXZ11YTRRROOOOZ11VRRRR1111111Z        \n";
		outputFile << "   111111111111111111111OOOOY111111ZOOOOZ1111111111111111       \n";
		outputFile << "   111111111111111111111OOOOY111111ZOOOOZ1111111111111111       \n";
		outputFile << "            OOOOOOOOOOOO    1111111ZOOOOOOOON  NOOOOOOORY1111   \n";
		outputFile << "            OOOOOOOOOOOO    1111111ZOOOOOOOON  NOOOOOOORY1111   \n";
		outputFile << "               111111          Z111ZOOOOOOOON          111111   \n";
		outputFile << "               111111          Z111ZOOOOOOOON          111111   \n";
		outputFile << "               111111       OOOQX11ZOOOO                        \n";
		outputFile << "               111111       OOOQX11ZOOOO                        \n";
		outputFile << "               ZZZZZZ       UUUVY11ZOOOO                        \n";
		outputFile << "                            1111111ZOOOO                        \n";
		outputFile << "                            1111111ZOOOO                        \n";
		outputFile << "                            1111111ZOOOO                        \n";
		outputFile << "                            ZZZZZ11ZOOOO                        \n";
		outputFile << "                            OOOQX11ZOOOO                        \n";
		outputFile << "                            OOOQX11ZOOOO                        \n";
	}
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}
