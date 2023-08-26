/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:03:56 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/03 11:59:07 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void)
{
	index = -1;
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

int	Contact::ft_getIndex(void) const
{
	return (index);
}

std::string Contact::ft_getInput(std::string str) const
{
	std::string input;
	bool		validInput;

	input = "";
	do {
		if (input.empty())
		{
			std::cout << str << std::flush;
			std::getline(std::cin, input);
			if (std::cin.good() && !input.empty())
				validInput = true;
			else {
				std::cin.clear();
				std::cout << "Invalid input, please try again." << std::endl;
				validInput = false;
			}
		}
	} while (!validInput);
	return (input);
}

std::string Contact::ft_print(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::ft_printTableLine(void) const
{
	if (index == -1)
		std::cout << "|" << std::setw(10) << std::flush;
	else
		std::cout << "|" << std::setw(9) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(first_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(last_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->ft_print(nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::ft_printContact(void) const
{
	std::cout << "Contact nº " << index << ":" << std::endl;
	std::cout << "\tFirst name:\t" << first_name << std::endl;
	std::cout << "\tLast name:\t" << last_name << std::endl;
	std::cout << "\tNickname:\t" << nickname << std::endl;
	std::cout << "\tPhone number:\t" << phone_number << std::endl;
	std::cout << "\tDarkest secret:\t" << darkest_secret << std::endl;
	std::cout << std::endl;
}

void	Contact::ft_newContact(int i)
{
	index = i;
	first_name = this->ft_getInput("First name: ");
	last_name = this->ft_getInput("Last name: ");
	nickname = this->ft_getInput("Nickname: ");
	phone_number = this->ft_getInput("Phone number: ");
	darkest_secret = this->ft_getInput("Darkest secret: ");
}
