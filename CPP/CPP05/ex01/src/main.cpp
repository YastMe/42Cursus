/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:36:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/19 12:08:52 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	jim("Jim", 1);
	Bureaucrat	tom("Tom", 150);
	AForm		gold("Gold Permit", 1, 1);
	AForm		wood("Wood Permit", 150, 150);

	std::cout << jim << std::endl;
	std::cout << tom << std::endl;
	std::cout << gold << std::endl;
	std::cout << wood << std::endl;

	tom.signForm(gold);
	std::cout << gold << std::endl;
	jim.signForm(gold);
	std::cout << gold << std::endl;
	tom.signForm(wood);
	std::cout << wood << std::endl;

	return (0);
}

