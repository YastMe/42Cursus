/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:22:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 20:06:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main(void)
{
	std::srand(time(NULL));
	for (int i = 0; i < std::rand() % 10; i++)
		std::rand();
	FragTrap frank("Frank");

	frank.attack("a rock");
	frank.takeDamage(5);
	frank.beRepaired(5);
	frank.highFivesGuys();
	for (int i = 0; i < 98; i++)
		frank.attack("a rock");
	frank.highFivesGuys();

	return (0);
}
