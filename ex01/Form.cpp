/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:58 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 15:36:53 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	(void) obj;
}

Form &Form::operator=(const Form &obj)
{
	(void)obj;
	return *this;
}

Form::~Form()
{
	// std::cout << "Form destructor called" << std::endl;
}


std::string	Form::getName()
{
	return this->_name;
}

bool        Form::getStatus()
{
	return this->_signed;
}

int   Form::getToSign()
{
	return this->_gradeToSign;
}

int	Form::getToExecute()
{
	return this->_gradeToExecute;
}

void	Form::beSigned(Bureaucrat &obj)
{
	this->_signed = true;
	std::cout << obj.getName() << " signed " << this->_name << std::endl;
}

Form::GradeTooHighException::GradeTooHighException() throw()
{
	this->message = "Form exception : grade is too High";
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return this->message.c_str();
}

Form::GradeTooLowException::GradeTooLowException() throw ()
{
	this->message = "Form exception : Grade is too Low";
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return this->message.c_str();
}

std::ostream &operator<<(std::ostream &os, Form &obj)
{
	os << "Form " << obj.getName() << std::endl;
	if (obj.getStatus() == 0)
		os << "Status :  not signed" << std::endl;
	else
		os << "Status : signed" << std::endl;
	os << "Needed grade to sign : " << obj.getToSign() << std::endl;
	os << "Needed grade to execute :" << obj.getToExecute() << std::endl;

	return os;
}


