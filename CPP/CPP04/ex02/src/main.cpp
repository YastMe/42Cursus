/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:48 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 16:17:04 by abeltran         ###   ########.fr       */
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
	
	// Animal	animal; //<-- Abstract class, won't compile as it's unable to be instantiated.
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;
	std::cout << "Exiting." << std::endl << std::endl;
	return (0);
}
