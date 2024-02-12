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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::string s = "Anne";
	std::string s2 = "Jose";
	std::string s3 = "Monique";

	Bureaucrat *B = NULL;
	Bureaucrat *B2 = NULL;
	Bureaucrat *B3 = NULL;

	AForm *S = NULL;
	AForm *P = NULL;
	AForm *R = NULL;

	try {
		B = new Bureaucrat(s, 120);
	}
	catch (std::exception &e)
	{
		std::cout << "On Bureaucrat constructor " << e.what() << std::endl;
		return 0;
	}

	try {
		B2 = new Bureaucrat(s2, 5);
	}
	catch (std::exception &e)
	{
		std::cout << "On Bureaucrat constructor " << e.what() << std::endl;
		delete B;
		return 0;
	}

	try {
		B3 = new Bureaucrat(s3, 20);
	}
	catch (std::exception &e)
	{
		std::cout << "On Bureaucrat constructor " << e.what() << std::endl;
		delete B;
		delete B2;
		return 0;
	}

	S = new ShrubberyCreationForm(std::string("Jennfifer_Lopez"));
	B->signForm(*S);
	B->executeForm(*S);

	std::cout << std::endl;

	P = new PresidentialPardonForm(std::string("Aerith"));
	B2->signForm(*P);
	B2->executeForm(*P);

	std::cout << std::endl;

	R = new RobotomyRequestForm(std::string("Crash Bandicoot"));
	B3->signForm(*R);
	B3->executeForm(*R);




	delete B;
	delete B2;
	delete B3;
	delete S;
	delete P;
	delete R;
}
