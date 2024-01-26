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

Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
		{
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			throw GradeTooLowException();
		}
		else
			this->_grade = grade;
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << e.what() << '\n';
		this->_grade = 150;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << '\n';
		this->_grade = 150;
	}
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
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(Form& obj)
{
	try
	{
		if (this->_grade > obj.getToSign())
			throw SignGradeTooLow(obj.getName(), this->getName());
		else if (obj.getStatus())
			throw AlreadySigned();
		else
			obj.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}



Bureaucrat::GradeTooHighException::GradeTooHighException() throw ()
{
	this->message = "Error. Grade is too High";
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return this->message.c_str();
}




Bureaucrat::GradeTooLowException::GradeTooLowException() throw ()
{
	this->message = "Error. Grade is too Low";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return this->message.c_str();
}



Bureaucrat::AlreadySigned::AlreadySigned() throw ()
{
	this->message = "Error. The form has already been signed";
}

const char *Bureaucrat::AlreadySigned::what() const throw ()
{
	return this->message.c_str();
}


Bureaucrat::SignGradeTooLow::SignGradeTooLow(std::string Form, std::string Bureaucrat) throw () : _bureaucrat(Bureaucrat), _form(Form)
{
}

const char *Bureaucrat::SignGradeTooLow::what() const throw ()
{
	static std::string message = this->_bureaucrat + std::string(" couldn't sign ") + this->_form + " because its grade is too low";
	return (message.c_str());
}
