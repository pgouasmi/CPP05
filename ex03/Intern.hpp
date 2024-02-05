/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:12:06 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 14:28:08 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#pragma once

#include "AForm.hpp"

class Intern
{

private:
std::string _keys[3];

//typedef void (AForm::*PtrFunction)();
AForm *(Intern::*_FunctionArray[3])(const std::string &target);

AForm	*spawnRobotomy(const std::string &target);
AForm	*spawnShrubbery(const std::string &target);
AForm	*spawnPardon(const std::string &target);


public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);
    ~Intern();

    AForm *makeForm(std::string &name, std::string &target);

	class UnknownFormException : public std::exception
	{
	private:
		std::string message;
	public:
		UnknownFormException() throw();
		virtual ~UnknownFormException() throw() {}
		virtual const char *what() const throw();
	};

};

#endif
