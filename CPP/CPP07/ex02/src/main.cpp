/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:42:31 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/09 17:07:59 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

# include <iostream>
# include <time.h>
# include <stdlib.h>

int main(void)
{
	Array<int>	first(10);
	Array<int>	second(10);

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		first[i] = rand() % 10;
		second[i] = rand() % 10;
	}

	std::cout << "First array: ";
	for (int i = 0; i < 10; i++)
		std::cout << first[i] << " ";
	std::cout << std::endl;

	std::cout << "Second array: ";
	for (int i = 0; i < 10; i++)
		std::cout << second[i] << " ";
	std::cout << std::endl;

	std::cout << "Equal operator; first = second: ";
	first = second;
	for (int i = 0; i < 10; i++)
		std::cout << first[i] << " ";
	std::cout << std::endl;

	std::cout << "Substitute first element of first array by 413." << std::endl;
	first[0] = 413;
	std::cout << "First array: ";
	for (int i = 0; i < 10; i++)
		std::cout << first[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "first[20]: " << first[20] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return (0);
}
