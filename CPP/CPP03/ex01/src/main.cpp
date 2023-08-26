/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:22:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 20:05:56 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void)
{
	std::srand(time(NULL));
	for (int i = 0; i < std::rand() % 10; i++)
		std::rand();
	ScavTrap sam("Sam");
	
	sam.attack("unsuspecting target");
	sam.takeDamage(10);
	sam.beRepaired(10);
	sam.guardGate();
	for (int i = 0; i < 47; i++)
		sam.attack("unsuspecting target");
	sam.attack("unsuspecting target");
	sam.guardGate();
	sam.beRepaired(10);
	sam.takeDamage(100);
	sam.attack("unsuspecting target");
	sam.guardGate();

	return (0);
}
