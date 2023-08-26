/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:05:15 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/18 11:11:56 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG_MSG << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << INFO_MSG << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << WARNING_MSG << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << ERROR_MSG << std::endl;
}

static int strToLevel(std::string level)
{
	if (!level.compare(DEBUG))
		return (DEBUG_LVL);
	else if (!level.compare(INFO))
		return (INFO_LVL);
	else if (!level.compare(WARNING))
		return (WARNING_LVL);
	else if (!level.compare(ERROR))
		return (ERROR_LVL);
	return (-1);
}

void	Harl::complain(std::string level)
{
	int			lvl = strToLevel(level);

	switch (lvl)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
	
}
