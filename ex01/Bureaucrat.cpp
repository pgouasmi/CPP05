/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 14:31:27 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name)
{
	if (grade < 1)
	{
		this->_grade = 150;
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		this->_grade = 150;
		throw GradeTooLowException();
	}
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name)
{
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	this->_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream	&operator<<(std::ostream &os,  Bureaucrat &obj)
{
	os << obj.getName() << ", Bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

const std::string	&Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &obj)
{
	if (this->_grade > obj.getToSign())
		throw GradeTooLowException();
	else if (obj.getStatus())
		throw AlreadySigned();
	else
		obj.beSigned(*this);
}



Bureaucrat::GradeTooHighException::GradeTooHighException() throw ()
{
	this->message = "Grade is too High";
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return this->message.c_str();
}




Bureaucrat::GradeTooLowException::GradeTooLowException() throw ()
{
	this->message = "Grade is too Low";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return this->message.c_str();
}


Bureaucrat::AlreadySigned::AlreadySigned() throw ()
{
	this->message = "Form is already signed";
}

const char *Bureaucrat::AlreadySigned::what() const throw ()
{
	return this->message.c_str();
}

