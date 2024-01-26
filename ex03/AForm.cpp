/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:24 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:06:41 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(1), _gradeToExecute(1)
{

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	try
	{
		// this->_gradeToSign = gradeToSign;
		// this->_gradeToExecute = gradeToExecute;
		// this->_signed = 0;
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
		else if (gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const AForm &obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	(void) obj;
}

AForm &AForm::operator=(const AForm &obj)
{
	// this->_name = obj._name;
	this->_signed = obj._signed;
	// this->_gradeToSign = obj._gradeToSign;
	// this->_gradeToExecute = obj._gradeToExecute;

	return *this;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}


std::string	AForm::getName()
{
	return this->_name;
}

bool        AForm::getStatus()
{
	return this->_signed;
}

int   AForm::getToSign()
{
	return this->_gradeToSign;
}

int	AForm::getToExecute()
{
	return this->_gradeToExecute;
}

// void	AForm::beSigned(Bureaucrat &obj)
// {
// 	if (this->getStatus() == 1)
// 	{
// 		std::cerr << "AForm " << this->getName() << " has already been signed" << std::endl;
// 		return ;
// 	}
// 	if (obj.getGrade() <= this->getToSign())
// 		this->_signed = 1;
// 	obj.signAForm(*this);
// }


void	AForm::beSigned(Bureaucrat &obj)
{
	try
	{
		// if (this->getStatus() == 1)
		// {
		// 	std::cerr << "AForm " << this->getName() << " has already been signed" << std::endl;
		// 	return ;
		// }
		if (obj.getGrade() > this->getToSign())
			throw GradeTooLowException();
		else
			this->_signed = 1;
		obj.signForm(*this);
	}
	catch(const std::exception &e)
	{
		obj.signForm(*this);
		std::cerr << e.what() << std::endl;
	}
}

AForm::GradeTooHighException::GradeTooHighException() throw()
{
	this->message = "AForm exception : grade is too High";
}

const char *AForm::GradeTooHighException::what() const throw ()
{
	return this->message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException() throw ()
{
	this->message = "AForm exception : Grade is too Low";
}

const char *AForm::GradeTooLowException::what() const throw ()
{
	return this->message.c_str();
}

std::ostream &operator<<(std::ostream &os, AForm &obj)
{
	os << "AForm " << obj.getName() << std::endl;
	if (obj.getStatus() == 0)
		os << "Status :  not signed" << std::endl;
	else
		os << "Status : signed" << std::endl;
	os << "Needed grade to sign : " << obj.getToSign() << std::endl;
	os << "Needed grade to execute :" << obj.getToExecute() << std::endl;

	return os;
}
