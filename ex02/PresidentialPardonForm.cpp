/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:44 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:27:21 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(0, 25)// _signed(0), _gradeToSign(25), _gradeToExecute(5), _target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _signed(0), _gradeToSign(25), _gradeToExecute(5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute), _target(obj._target)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->_signed = obj._signed;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
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
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

