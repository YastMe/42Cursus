/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:19:20 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 19:31:16 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default constructor called on " << this << std::endl;
	_name = "Generic ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "Name constructor called on " << this << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "[ScavTrap " << _name << "]: ";
	randStartMessage();
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap._name)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	std::cout << "[ScavTrap " << _name << "]: ";
	randStartMessage();
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called on " << this << std::endl;
	std::cout << "[ScavTrap " << _name << "]: ";
	randDeathMessage();
}

ScavTrap & ScavTrap::operator = (const ScavTrap &scavtrap)
{
	std::cout << "Copy operator called on " << this << std::endl;
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;

	return (*this);
}

void	ScavTrap::randGuardGateMessage(void)
{
	switch (std::rand() % 4)
	{
	case 0:
		std::cout << "Gate secure. As if there was ever any doubt." << std::endl;
		break;
	case 1:
		std::cout << "Guarding the gate like a boss. No trespassing on my watch!" << std::endl;
		break;
	case 2:
		std::cout << "Securing the gate like a pro. No intruders allowed, obviously." << std::endl;
		break;
	case 3:
		std::cout << "Guarding gate. Password? Just kidding. I don't care, you're not getting in." << std::endl;
		break;
	}
}

void	ScavTrap::randStartMessage(void)
{
	switch (std::rand() % 4)
	{
		case 0:
			std::cout << "Deployment complete. Time to show this place some robotic charm." << std::endl;
			break;
		case 1:
			std::cout << "Unpacked and unfazed. This place just got upgraded." << std::endl;
			break;
		case 2:
			std::cout << "Greetings, new territory. Brace yourself for some robotic charm." << std::endl;
			break;
		case 3:
			std::cout << "Touching down in a new domain. Prepare for unparalleled wit." << std::endl;
			break;
		default:
			break;
	}
}

void	ScavTrap::randDeathMessage(void)
{
	switch (std::rand() % 4)
	{
	case 0:
		std::cout << "Well, that escalated quickly." << std::endl;
		break;
	case 1:
		std::cout << "Operation 'Stay Alive' didn't quite go as planned, huh?" << std::endl;
		break;
	case 2:
		std::cout << "Note to future, not dead, self: Avoid whatever that was." << std::endl;
		break;
	case 3:
		std::cout << "Immortal until proven otherwise. Spoiler: Proven otherwise." << std::endl;
		break;
	default:
		break;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "[ ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! ] [ " << _energyPoints << " energy points left ]" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "[ScavTrap " << _name << " attack]: How am I supposed to attack when I'm dead?!" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "[ScavTrap " << _name << " attack]: I see you're attempting the impossible: attacking with no juice left. Classic." << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "[ScavTrap " << _name << "]: ";
		randGuardGateMessage();
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "[ScavTrap " << _name << " guardGate]: I'm too dead to be guarding a gate." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "[ScavTrap " << _name << " guardGate]: Not happening, too tired. The gate can guard itself." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &scavtrap)
{
	out << "ScavTrap [" << scavtrap.getName() << "]";
	return (out);
}