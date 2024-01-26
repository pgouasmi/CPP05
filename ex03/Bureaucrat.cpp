/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 12:53:27 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		this->_grade = grade;
		if (this->_grade < 1)
			throw GradeTooLowException();
		else if (this->_grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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

const std::string	&Bureaucrat::getName() const
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
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &obj) const
{
	if (obj.getStatus() == 0)
		std::cout << this->getName() << " couldn't sign " << obj.getName() << " because this bureaucrat's Grade is too low" << std::endl;
	else
		std::cout << this->getName() << " signed " << obj.getName() << std::endl;
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

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (this->_grade > ((AForm &)form).getToExecute())
			throw GradeTooLowException();
		else if (((AForm &)form).getStatus() == 0)
			std::cout << "The form has not been signed beforehand, can not execute it" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execution :" << e.what() << '\n';
	}

}


