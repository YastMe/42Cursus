/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:15 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 12:58:27 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &animal);
		virtual ~Animal();

		Animal & operator = (const Animal &animal);

		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const Animal &animal);

#endif