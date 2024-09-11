/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:36:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/07/08 17:59:58 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				jim("Jim", 1);
	Bureaucrat				tom("Tom", 150);
	ShrubberyCreationForm	test("test");
	RobotomyRequestForm		robot("Max");
	PresidentialPardonForm	pardon("Karen");

	std::cout << jim << std::endl;
	std::cout << tom << std::endl;

	std::srand(time(NULL));

	try
	{
		test.execute(jim);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test.beSigned(tom);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test.beSigned(jim);
		test.execute(jim);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		robot.beSigned(tom);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		robot.beSigned(jim);
		robot.execute(jim);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		pardon.beSigned(tom);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		pardon.beSigned(jim);
		pardon.execute(jim);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

