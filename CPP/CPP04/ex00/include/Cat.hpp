/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:11 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 12:51:55 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
	private:
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();

		Cat & operator = (const Cat &cat);

		void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const Cat &cat);

#endif