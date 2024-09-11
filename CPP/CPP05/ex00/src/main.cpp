/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:36:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/18 13:41:46 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	jim("Jim", 1);
	Bureaucrat	tom("Tom", 150);

	std::cout << jim << std::endl;
	std::cout << tom << std::endl;


	jim.decrementGrade();
	tom.incrementGrade();

	std::cout << jim << std::endl;
	std::cout << tom << std::endl;

	try
	{
		Bureaucrat	steve("Steve", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	steve("Steve", 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		jim.incrementGrade();
		std::cout << jim << std::endl;
		jim.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		tom.decrementGrade();
		std::cout << tom << std::endl;
		tom.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

