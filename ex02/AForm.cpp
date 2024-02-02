/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 15:36:53 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	(void) obj;
}

AForm &AForm::operator=(const AForm &obj)
{
	(void) obj;
	return *this;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}


std::string	AForm::getName() const
{
	return this->_name;
}

bool        AForm::getStatus() const
{
	return this->_signed;
}

int   AForm::getToSign() const
{
	return this->_gradeToSign;
}

int	AForm::getToExecute() const
{
	return this->_gradeToExecute;
}

void	AForm::setStatus(bool value)
{
	this->_signed = value;
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (this->_signed)
		throw AlreadySignedException();
	if (obj.getGrade() > this->getToSign())
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << obj.getName() << " signed form " << this->_name << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException() throw()
{
	this->message = "grade is too High";
}

const char *AForm::GradeTooHighException::what() const throw ()
{
	return this->message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException() throw ()
{
	this->message = "Grade is too Low";
}

const char *AForm::GradeTooLowException::what() const throw ()
{
	return this->message.c_str();
}

AForm::NotSignedException::NotSignedException() throw ()
{
	this->message = "Form has not been signed";
}

const char *AForm::NotSignedException::what() const throw ()
{
	return this->message.c_str();
}

AForm::AlreadySignedException::AlreadySignedException() throw ()
{
	this->message = "Form has already been signed";
}

const char *AForm::AlreadySignedException::what() const throw ()
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


