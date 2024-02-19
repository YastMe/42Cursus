/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:07:48 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:10:14 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
	public:
		WrongCat();
		WrongCat(const WrongCat &wrongcat);
		~WrongCat();

		WrongCat & operator = (const WrongCat &wrongcat);

		void	makeSound(void) const;
};

std::ostream & operator << (std::ostream &out, const WrongCat &wrongcat);

#endif