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

	Bureaucrat *A = new Bureaucrat(s, 4);
	Bureaucrat *B = new Bureaucrat(s, 56);
	Form *C = NULL;
//	Form *C;

	std::cout << *A << std::endl;
	std::cout << *B << std::endl;
	std::cout << std::endl;

	try
	{
		C = new Form(std::string("2B"), 200, 60);
		std::cout << *C << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete A;
		delete B;
		delete C;
		return 1;
	}

//	C->beSigned(*B);
//	C->beSigned(*A);

	delete A;
	delete B;
	delete C;
	return 0;
}
