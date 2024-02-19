/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:48 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:23:01 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

void	ftVoid(void)
{
	system("leaks -q animals");
}

int main()
{
	atexit(ftVoid);
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete cat;
	delete dog;

	/*-------------------------*/

	const WrongAnimal	*metaWrong = new WrongAnimal();
	const WrongAnimal	*catWrong = new WrongCat();

	std::cout << metaWrong->getType() << " " << std::endl;
	std::cout << catWrong->getType() << " " << std::endl;

	catWrong->makeSound();
	metaWrong->makeSound();

	delete catWrong;
	delete metaWrong;
	
	/*-------------------------*/

	std::cout << "Exiting." << std::endl << std::endl;

	return (0);
}
