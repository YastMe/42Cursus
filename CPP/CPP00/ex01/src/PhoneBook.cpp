/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:29:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/02 18:22:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int		PhoneBook::ft_readIndex(void) const {
	int			index;
	std::string	input;
	bool		validIndex;

	do {
		std::cout << "Enter the contact index: ";
		std::getline(std::cin, input);
		index = std::atoi(input.c_str());
		for (int i = 0; i < 8; i++) {
			if (index >= 0 && contacts[i].ft_getIndex() == index) {
				validIndex = true;
				break;
			}
			else
				validIndex = false;
		}
		if (!validIndex)
			std::cout << "Invalid index, please try again." << std::endl;
	} while (!validIndex);
	return (index);
}

void		PhoneBook::ft_printContact(int index) const {
	contacts[index % 8].ft_printContact();
}

void		PhoneBook::ft_printTable(void) const {
	std::cout << "|" << std::setw(9) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++) {
		contacts[i].ft_printTableLine();
	}
}

void	PhoneBook::ft_welcome(void) const {
	std::cout << "Welcome to your phonebook!" << std::endl;
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "ADD: Add a new contact" << std::endl;
	std::cout << "SEARCH: Search for a contact" << std::endl;
	std::cout << "EXIT: Exit the phonebook" << std::endl;
}

void	PhoneBook::ft_addContact(void) 
{
	int	maxIndex;

	maxIndex = ft_getMaxIndex() + 1;
	contacts[maxIndex % 8].ft_newContact(maxIndex);
}

int	PhoneBook::ft_getMaxIndex(void) const
{
	int	maxIndex;

	maxIndex = contacts[0].ft_getIndex();
	for (int i = 0; i < 8; i++) {
		if (contacts[i].ft_getIndex() > maxIndex) {
			maxIndex = i;
		}
	}
	return (maxIndex);
}
