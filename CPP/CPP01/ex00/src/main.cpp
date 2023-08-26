/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:00:27 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/10 12:29:46 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"


int main(void)
{
	Zombie *z = newZombie("Genovevo");
	randomChump("Evaristo");
	z->announce();
	delete z;
	return (0);
}