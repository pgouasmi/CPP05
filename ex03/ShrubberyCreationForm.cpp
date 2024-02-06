/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:57 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:22:18 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("default", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("default", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
	(void) obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->setStatus(obj.getStatus());
	this->_target = obj._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getToExecute())
	{
		throw GradeTooLowException();
	}
	else if (this->getStatus() == 0)
	{
		throw NotSignedException();
	}
	std::cout << executor.getName() << " executed ShrubberyCreationForm " << this->getName() << std::endl;
	std::ofstream ofs;
	ofs.open((this->_target + std::string("_shrubberry")).c_str(), std::ofstream::out | std::ofstream::trunc);
	ofs <<
	"    oxoxoo    ooxoo\n"
"  ooxoxo oo  oxoxooo\n"
" oooo xxoxoo ooo ooox\n"
" oxo o oxoxo  xoxxoxo\n"
"  oxo xooxoooo o ooo\n"
"    ooo\\oo\\  /o/o\n"
"        \\  \\/ /\n"
"         |   /\n"
"         |  |\n"
"         | D|\n"
"         |  |\n"
"         |  |\n"
"  ______/____\\_\\___\n";
}
