/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:53:43 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/02 18:22:52 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];

	public:

		/**
		 * @brief Reads the contact index from the user.
		 * 
		 * @return int 
		 */
		int		ft_readIndex(void) const;

		/**
		 * @brief Prints the contact information.
		 * 
		 * @param index 
		 */
		void	ft_printContact(int index) const;

		/**
		 * @brief Prints the full contact table.
		 * 
		 */
		void	ft_printTable(void) const;

		/**
		 * @brief Prints the welcome message.
		 * 
		 */
		void	ft_welcome(void) const;

		/**
		 * @brief Adds a new contact to the phonebook, replacing the oldest one if the phonebook is full.
		 * 
		 */
		void	ft_addContact(void);

		/**
		 * @brief Returns the index of the oldest contact.
		 * 
		 * @return int 
		 */
		int		ft_getMaxIndex(void) const;
};

#endif
