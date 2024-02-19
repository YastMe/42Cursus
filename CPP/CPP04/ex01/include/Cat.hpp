/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:11 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 15:47:32 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat(Brain &brain);
		~Cat();

		Cat & operator = (const Cat &cat);

		void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const Cat &cat);

#endif