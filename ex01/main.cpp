/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:58:37 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 15:32:30 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::string s = "Gertrude";
	std::string s2 = "Anne";

	Bureaucrat *A = new Bureaucrat(s, 4);
	Bureaucrat *B = new Bureaucrat(s2, 56);
	Form *C = NULL;
	Form *D = NULL;

	std::cout << *A << std::endl;
	std::cout << *B << std::endl;
	std::cout << std::endl;

	try
	{
		C = new Form(std::string("2B"), 20, 60);
		std::cout << *C << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		D = new Form("2A", 10, 60);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B->signForm(*D);
	}
	catch (std::exception &e)
	{
		std::cout << B->getName() << " could not sign " << D->getName() << " because " << e.what() << std::endl;
	}

	try
	{
		A->signForm(*D);
	}
	catch (std::exception &e)
	{
		std::cout << A->getName() << " could not sign " << D->getName() << " because " << e.what() << std::endl;
	}


	delete A;
	delete B;
	delete C;
	delete D;
	return 0;
}
