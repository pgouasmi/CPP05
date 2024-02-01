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

ShrubberyCreationForm::ShrubberyCreationForm() :  AForm("default", 145, 137), _target("default")//_signed(false), _gradeToSign(145), _gradeToExecute(137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("default", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute), _target(obj._target)
{
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->_signed = obj._signed;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
	{
		throw GradeTooLowException();
	}
	else if (((AForm *)this)->getStatus() == 0)
	{
		throw NotSignedException();
	}
	std::ofstream ofs;
	ofs.open((executor.getName() + std::string("_shrubberry")).c_str(), std::ofstream::out | std::ofstream::trunc);
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

