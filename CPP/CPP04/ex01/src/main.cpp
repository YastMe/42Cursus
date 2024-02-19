/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:48 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 16:26:58 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

void	ftVoid(void)
{
	system("leaks -q animals");
}

int main()
{
	atexit(ftVoid);
	
	Animal	*animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	*animals[0] = *animals[2];
	
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "Exiting." << std::endl << std::endl;
	return (0);
}
