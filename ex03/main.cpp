/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:58:37 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/26 13:25:56 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
//#include "PresidentialPardonForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string s = "Anne";
	std::string type = "robotomy request";
	std::string target = "bruh";
	AForm *S = NULL;

	Intern *I = new Intern();

	try
	{
		S = I->makeForm(type, target);
	}
	catch (std::exception &e)
	{
		std::cout << "Make Form failed because " << e.what() << std::endl;
		delete I;
		return 1;

	}
	Bureaucrat *B = new Bureaucrat(s, 1);

	if (S) {
		B->signForm(*S);
		B->executeForm(*S);
	}

	delete I;
	delete S;
	delete B;

	return 0;
}
