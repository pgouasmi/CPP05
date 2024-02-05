/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:23 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 14:24:51 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <ostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
public:
	Bureaucrat();

	Bureaucrat(std::string &name, int grade);

	Bureaucrat(Bureaucrat const &obj);

	Bureaucrat &operator=(Bureaucrat const &obj);

	~Bureaucrat();

	const std::string &getName();

	int getGrade() const;

	void incrementGrade();

	void decrementGrade();

	void signForm(Form &obj);

private:
	const std::string _name;
	int _grade;


	class GradeTooHighException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooHighException() throw();

		virtual ~GradeTooHighException() throw() {};

		virtual const char *what() const throw();
	};


	class GradeTooLowException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooLowException() throw();

		virtual ~GradeTooLowException() throw() {};

		virtual const char *what() const throw();
	};

	class AlreadySigned : public std::exception {
	private:
		std::string message;
	public:
		AlreadySigned() throw();

		virtual ~AlreadySigned() throw() {}

		virtual const char *what() const throw();
	};
};

std::ostream&   operator<<(std::ostream &os,  Bureaucrat &obj);


#endif
