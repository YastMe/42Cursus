/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:26:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 19:50:03 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default constructor called on " << this << std::endl;
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap " << _name << "]: ";
	randStartMessage();
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "Name constructor called on " << this << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "[FragTrap " << _name << "]: ";
	randStartMessage();
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called on " << this << std::endl;
	std::cout << "[FragTrap " << _name << "]: ";
	randDeathMessage();
}

FragTrap & FragTrap::operator = (const FragTrap &fragtrap)
{
	std::cout << "Copy operator called on " << this << std::endl;
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;

	return (*this);
}

void FragTrap::randStartMessage(void)
{
	switch (std::rand() % 4)
	{
		case 0:
			std::cout << "Bro pass me the protein shake." << std::endl;
			break;
		case 1:
			std::cout << "Man, I'm so pumped up!" << std::endl;
			break;
		case 2:
			std::cout << "Bro bro bro, after today's workout I'm gonna be so ripped." << std::endl;
			break;
		case 3:
			std::cout << "Dude, let's get this going!" << std::endl;
			break;
		default:
			break;
	}
}

void FragTrap::randDeathMessage(void)
{
	switch (std::rand() % 4)
	{
		case 0:
			std::cout << "Naaah bro low hp? I'm out!" << std::endl;
			break;
		case 1:
			std::cout << "Bro I'm out of here!" << std::endl;
			break;
		case 2:
			std::cout << "Dude, that's rough." << std::endl;
			break;
		case 3:
			std::cout << "Yo, bro, I'm out." << std::endl;
			break;
		default:
			break;
	}
}

void FragTrap::randHighFivesMessage(void)
{
	switch (std::rand() % 4)
	{
		case 0:
			std::cout << "Yooo high fives bro! Up top!" << std::endl;
			break;
		case 1:
			std::cout << "Bro bro bro hear me out bro: high five!" << std::endl;
			break;
		case 2:
			std::cout << "Duuude high five!" << std::endl;
			break;
		case 3:
			std::cout << "High fives? High fives!" << std::endl;
			break;
		default:
			break;
	}
}

void FragTrap::highFivesGuys(void)
{
	if (_energyPoints && _hitPoints)
	{
		std::cout << "[FragTrap " << _name << "]: ";
		randHighFivesMessage();
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "[FragTrap " << _name << " highFivesGuys]: Hey, I'm dead, I can't high five you." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "[FragTrap " << _name << " highFivesGuys]: Bro knows I like high fives, but I'm out of energy." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &fragtrap)
{
	out << "FragTrap [" << fragtrap.getName() << "]";
	return (out);
}