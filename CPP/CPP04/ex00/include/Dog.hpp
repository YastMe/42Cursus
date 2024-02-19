/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:18 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 12:52:02 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
	private:
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();

		Dog & operator = (const Dog &dog);

		void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const Dog &dog);

#endif