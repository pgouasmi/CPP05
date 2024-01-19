/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/19 17:28:49 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string &name, int grade)
{
	try
	{
		this->_name = name;
		this->_grade = grade;
		if (this->_grade < 0 || this->_grade > 150)
			throw std::out_of_range("Grade must be between 0 and 150");
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
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

std::string	&Bureaucrat::getName()
{
	return this->_name;
}

void	Bureaucrat::setName(std::string name)
{
	try
	{
		this->_name = name;
		if (this->_name.empty())
			throw std::exception()
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
