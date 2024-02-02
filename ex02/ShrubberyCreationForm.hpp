/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:43:59 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:18:45 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#pragma once

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &name);
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
    virtual~ShrubberyCreationForm();

    void    execute(Bureaucrat const &executor) const;
    // void        beSigned(Bureaucrat &obj);


private:
//    const std::string _name;
//    bool              _signed;
//    const int         _gradeToSign;
//    const int         _gradeToExecute;
	std::string _target;

    // std::string getName();
    // bool        getStatus();
    // int         getToSign();
    // int         getToExecute();



};

#endif
