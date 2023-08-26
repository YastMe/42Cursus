/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:26:16 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/03 12:02:48 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private:
		// Variables
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;
		int				index;

		// Functions
		/**
		 * @brief Gets the input from the user.
		 * 
		 * @param str 
		 * @return std::string 
		 */
		std::string		ft_getInput(std::string str) const;

		/**
		 * @brief Returns the given string correctly formatted.
		 * 
		 * @param str 
		 * @return std::string 
		 */
		std::string		ft_print(std::string str) const;
	
	public:
		// Constructor
		/**
		 * @brief Construct a new Contact object
		 * 
		 */
		Contact(void);

		// Getter
		/**
		 * @brief Returns the index of the contact.
		 * 
		 * @return int 
		 */
		int				ft_getIndex(void) const;

		// Print functions
		/**
		 * @brief Prints the correspondent contact line.
		 * 
		 */
		void			ft_printTableLine(void) const;
		
		/**
		 * @brief Prints the contact.
		 * 
		 */
		void			ft_printContact(void) const;

		// Misc functions
		/**
		 * @brief Reassigns the contact information.
		 * 
		 */
		void			ft_newContact(int i);
};

#endif
