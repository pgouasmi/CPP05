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
	std::string s = "Gertrude";

	Bureaucrat *B = new Bureaucrat(std::string("Anne"), 1);

	ShrubberyCreationForm *A = new ShrubberyCreationForm();

	A->beSigned(*B);
	A->execute(*B);

	PresidentialPardonForm *P = new PresidentialPardonForm();

	P->beSigned(*B);
	P->execute(*B);

	RobotomyRequestForm *R = new RobotomyRequestForm();

	R->beSigned(*B);
	R->execute(*B);




	// Bureaucrat *A = new Bureaucrat(s, 4);
	// Bureaucrat *B = new Bureaucrat(std::string("Anne"), 56);

	// std::cout << *A << std::endl;
	// std::cout << *B << std::endl;
	// std::cout << std::endl;

	// Form *C = new Form(std::string("2B"), 20, 60);

	// std::cout << *C << std::endl;

	// C->beSigned(*B);
	// C->beSigned(*A);

	// delete A;
	// delete B;
	// delete C;
	// return 0;
}
