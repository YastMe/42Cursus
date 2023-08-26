/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:54:58 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/02 17:56:53 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	bool		exit;

	phonebook.ft_welcome();
	do 	{
		exit = false;
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		std::cout << std::flush;
		if (input.compare("ADD") == 0)
			phonebook.ft_addContact();
		else if (input.compare("SEARCH") == 0)
		{
			if (phonebook.ft_getMaxIndex() == -1)
				std::cout << "Your phonebook is empty, you can start by adding your friends!" << std::endl;
			else
			{
				phonebook.ft_printTable();
				phonebook.ft_printContact(phonebook.ft_readIndex());
				std::cout << std::flush;
			}
		}
		else if (input.compare("EXIT") == 0)
		{
			exit = true;
			std::cout << "Goodbye!" << std::endl;
		}
	} while (!exit);

	return (0);
}