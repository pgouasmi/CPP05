/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:58:37 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/22 15:29:25 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::string s = "Gertrude";
	Bureaucrat *A = NULL;
	Bureaucrat *B = NULL;
	Bureaucrat *C = NULL;

	try {
		A = new Bureaucrat(s, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		B = new Bureaucrat(s, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << *A << std::endl;
	std::cout << *B << std::endl;

	*B = *A;

	std::cout << *B << std::endl;

	try {
		C = new Bureaucrat(s, 150);
		C->decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete A;
	delete B;
	delete C;
	return 0;
}
