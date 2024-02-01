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

#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string &name, int grade);
	Bureaucrat(Bureaucrat const &obj);
	Bureaucrat &operator=(Bureaucrat const &obj);
	~Bureaucrat();


	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &obj);
	void executeForm(AForm const &form);

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


	class AlreadySignedException : public std::exception {
	private:
		std::string message;
	public:
		AlreadySignedException() throw();
		virtual ~AlreadySignedException() throw() {}
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	private:
		std::string message;
	public:
		NotSignedException() throw();
		virtual ~NotSignedException() throw() {}
		virtual const char *what() const throw();
	};

};

std::ostream&   operator<<(std::ostream &os,  Bureaucrat &obj);


#endif
