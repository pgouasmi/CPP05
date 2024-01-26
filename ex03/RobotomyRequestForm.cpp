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

RobotomyRequestForm::RobotomyRequestForm() : _signed(0), _gradeToSign(72), _gradeToExecute(45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _signed(0), _gradeToSign(72), _gradeToExecute(45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute), _target(obj._target)
{
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->_signed = obj._signed;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
	{
		std::cout << "Executor " << executor.getName() << "'s grade is not high enough to execute the form " << ((AForm *)this)->getName() << std::endl;
		return ;
	}
	else if (((AForm *)this)->getStatus() == 0)
	{
		std::cout << "The form " << ((AForm *)this)->getName() << " has not been signed beforehand. Executor " << executor.getName() << " can not execute it." << std::endl;
		return ;
	}
	std::srand(std::time(NULL));
	int randomvalue = std::rand();
	if (randomvalue % 2)
		std::cout << "* BRRRRRRRRRRRRRRRRRRRRRRRRRRR *\n" << executor.getName() << " has been robotomized." << std::endl;
}
