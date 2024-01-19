/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:23 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/19 17:41:22 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat
{
public:
    Bureaucrat(std::string &name, int grade);
    Bureaucrat(Bureaucrat const &obj);
    Bureaucrat &operator=(Bureaucrat const &obj);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
    private:
        std::string message;
    public:
        GradeTooHighException(const std::string &msg) : message(msg) {}
        ~GradeTooHighException() {};
        const char* what() const noexcept override{
            return message.c_str();
        }
    };

    std::string &getName();
    void        setName(std::string name);
    int         getGrade();
    void        setGrade(int grade);

private:
    std::string _name;
    int         _grade;

};

#endif
