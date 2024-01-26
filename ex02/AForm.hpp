/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:34 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:38 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    virtual ~AForm() = 0;

    std::string getName();
    bool        getStatus();
    int         getToSign();
    int         getToExecute();
    void        beSigned(Bureaucrat &obj);
    virtual void    execute(Bureaucrat const &executor) const = 0;

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

std::ostream&   operator<<(std::ostream &os,  AForm &obj);

#endif
