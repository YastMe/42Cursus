/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:32:21 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 16:47:16 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./rpn \"expression\"" << DEFAULT << std::endl;
		return (1);
	}

	RPN rpn;
	rpn.calculate(argv[1]);
	return (0);
}
