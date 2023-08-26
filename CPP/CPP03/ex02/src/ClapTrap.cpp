/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:22:19 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/26 19:53:32 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called on " << this << std::endl;
	_name = "Generic ClapTrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "[ClapTrap " << _name << "]: ";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called on " << this << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "[ClapTrap " << _name << "]: ";
	randStartMessage();
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on " << this << std::endl;
	std::cout << "[ClapTrap " << _name << "]: ";
	randDeathMessage();
}

ClapTrap & ClapTrap::operator = (const ClapTrap &claptrap)
{
	std::cout << "Copy operator called on " << this << std::endl;
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
	return (*this);
}

void ClapTrap::randStartMessage(void)
{
	switch (std::rand() % 4)
	{
		case 0:
			std::cout << "Target acquired!" << std::endl;
			break;
		case 1:
			std::cout << "Hellooo." << std::endl;
			break;
		case 2:
			std::cout << "Sentry mode activated." << std::endl;
			break;
		case 3:
			std::cout << "Deploying." << std::endl;
			break;
		default:
			break;
	}
}

void ClapTrap::randTiredMessage(void)
{
	switch (std::rand() % 4)
	{
	case 0:
		std::cout << "Aah." << std::endl;
		break;
	case 1:
		std::cout << "Self test error." << std::endl;
		break;
	case 2:
		std::cout << "Malfunctioning." << std::endl;
		break;
	case 3:
		std::cout << "Sorry, we're closed." << std::endl;
		break;
	default:
		break;
	}
}

void ClapTrap::randDeathMessage(void)
{
	switch (std::rand() % 4)
	{
	case 0:
		std::cout << "I don't hate you." << std::endl;
		break;
	case 1:
		std::cout << "No hard feelings." << std::endl;
		break;
	case 2:
		std::cout << "Hibernating." << std::endl;
		break;
	case 3:
		std::cout << "Nap mode activated." << std::endl;
		break;
	default:
		break;
	}
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "[ ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! ] [ " << _energyPoints << " energy points left ]" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "[ClapTrap " << _name << " attack]: I discovered pacifism after I got shot!" << std::endl;
	else if (_energyPoints <= 0)
	{
		std::cout << "[ClapTrap " << _name << " attack]: ";
		randTiredMessage();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "[ ClapTrap " << _name << " takes " << amount << " points of damage! ]" << " [ " << _hitPoints << " HP left ]" << std::endl;
	}
	else
		std::cout << "[ClapTrap " << _name << "]: Why me? I'm already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "[ ClapTrap " << _name << " is repaired for " << amount << " hit points ] [ " << _hitPoints << " HP left ] [ " << _energyPoints << " energy points left ]" << std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "[ClapTrap " << _name << " repair]: Turns out you can't repair death!" << std::endl;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "[ClapTrap " << _name << " repair]: ";
		randTiredMessage();
	}
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &claptrap)
{
	out << "ClapTrap [" << claptrap.getName() << "]";
	return (out);
}