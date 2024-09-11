/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:05:56 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 11:12:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int>	vector;
	std::list<int>		list;

	std::cout << "Vector contents: ";
	for (int i = 0; i < 5; i++)
	{
		vector.push_back(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "List contents: ";
	for (int i = 5; i > 0; i--)
	{
		vector.push_back(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;

	int	test = 10;
	std::cout << "Searching for number " << test << " in vector." << std::endl;
	if (easyfind(vector, test))
		std::cout << test << " found!" << std::endl;
	else
		std::cout << test << " not found." << std::endl;

	test = 2;
	std::cout << "Searching for number " << test << " in vector." << std::endl;
	if (easyfind(vector, test))
		std::cout << test << " found!" << std::endl;
	else
		std::cout << test << " not found." << std::endl;

	test = 42;
	std::cout << "Searching for number " << test << " in list." << std::endl;
	if (easyfind(vector, test))
		std::cout << test << " found!" << std::endl;
	else
		std::cout << test << " not found." << std::endl;

	test = 4;
	std::cout << "Searching for number " << test << " in list." << std::endl;
	if (easyfind(vector, test))
		std::cout << test << " found!" << std::endl;
	else
		std::cout << test << " not found." << std::endl;

	return (0);
}

