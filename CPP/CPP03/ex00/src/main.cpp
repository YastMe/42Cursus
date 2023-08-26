/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:22:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 20:06:03 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
	std::srand(time(NULL));
	for (int i = 0; i < std::rand() % 10; i++)
		std::rand();
	ClapTrap carl("Carl");

	carl.attack("unsuspecting target");
	carl.takeDamage(5);
	carl.beRepaired(5);
	for (int i = 0; i < 9; i++)
		carl.attack("unsuspecting target");
	carl.beRepaired(10);
	carl.takeDamage(10);
	carl.attack("unsuspecting target");
	carl.beRepaired(10);

	return (0);
}
