/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:12:01 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 14:23:38 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string &name, std::string &target)
{

}
