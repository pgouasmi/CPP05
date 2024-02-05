/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:04 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/23 14:51:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
	const std::string _name;
	bool              _signed;
	const int         _gradeToSign;
	const int         _gradeToExecute;

public:
	AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    virtual ~AForm();

    std::string getName() const;
    bool        getStatus() const;
    int         getToSign() const;
    int         getToExecute() const;
	void		setStatus(bool value);
    void        beSigned(Bureaucrat &obj);
	virtual void		execute(Bureaucrat const &executor) const = 0;

    class GradeTooLowException : public std::exception
    {
    private:
        std::string message;
    public:
        GradeTooLowException() throw();
        virtual ~GradeTooLowException() throw() {};
        virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    private:
        std::string message;
    public:
        GradeTooHighException() throw();
        virtual ~GradeTooHighException() throw() {};
        virtual const char* what() const throw();
    };

	class AlreadySignedException : public std::exception
	{
	private:
		std::string message;
	public:
		AlreadySignedException() throw();
		virtual ~AlreadySignedException() throw() {};
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
	private:
		std::string message;
	public:
		NotSignedException() throw();
		virtual ~NotSignedException() throw() {};
		virtual const char* what() const throw();
	};

};

std::ostream&   operator<<(std::ostream &os,  AForm &obj);

#endif
