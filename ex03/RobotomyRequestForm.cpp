/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:51 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:28:07 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Default", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{
	(void)obj;
//	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->setStatus(obj.getStatus());
	this->_target = obj._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getToExecute())
	{
		throw GradeTooLowException();
	}
	else if (((AForm *)this)->getStatus() == 0)
	{
		throw NotSignedException();
	}
	std::cout << "* drilling noises *\nTrying a robotomy on the executor with a 50% chance of success" << std::endl;
	std::srand(std::time(NULL));
	int randomvalue = std::rand();
	if (randomvalue % 2)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
