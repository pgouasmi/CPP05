/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:12:01 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 14:23:38 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	this->_keys[0] = "robotomy request";
	this->_keys[1] = "presidential pardon";
	this->_keys[2] = "shrubbery creation";

	this->_FunctionArray[0] = &Intern::spawnRobotomy;
	this->_FunctionArray[1] = &Intern::spawnPardon;
	this->_FunctionArray[2] = &Intern::spawnShrubbery;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string &name, std::string &target)
{
	size_t i = 0;

	while (i < 3 && this->_keys[i] != name)
		i++;
	if (this->_keys[i] != name)
	{
		throw UnknownFormException();
	}
	else
	{
		std::cout << "Intern successfully created a new Form" << std::endl;
		return (this->*_FunctionArray[i])(target);
	}
}

Intern::UnknownFormException::UnknownFormException() throw()
{
	this->message = "unknown form";
}

const char * Intern::UnknownFormException::what() const throw()
{
	return this->message.c_str();
}

AForm *Intern::spawnPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::spawnRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::spawnShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
