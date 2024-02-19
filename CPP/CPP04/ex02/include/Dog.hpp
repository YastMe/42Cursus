/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:18 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 15:47:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog(Brain &brain);
		~Dog();

		Dog & operator = (const Dog &dog);

		void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const Dog &dog);

#endif