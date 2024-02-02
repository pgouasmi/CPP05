/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:04 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 14:51:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#pragma once

#include <string>

class Bureaucrat;

class Bureaucrat;

class Form
{
public:
	Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &obj);
    Form &operator=(const Form &obj);
    ~Form();

    std::string getName();
    bool        getStatus();
    int         getToSign();
    int         getToExecute();
    void        beSigned(Bureaucrat &obj);

private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;


    class GradeTooLowException : public std::exception
    {
    private:
        std::string message;
    public:
        GradeTooLowException() throw();
        virtual ~GradeTooLowException() throw() {};
        virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    private:
        std::string message;
    public:
        GradeTooHighException() throw();
        virtual ~GradeTooHighException() throw() {};
        virtual const char* what() const throw();
    };

};

std::ostream&   operator<<(std::ostream &os, Form &obj);

#endif
