/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:07:52 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:18:38 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wronganimal);
		virtual ~WrongAnimal();

		WrongAnimal & operator = (const WrongAnimal &wronganimal);

		virtual	void	makeSound(void) const;
		std::string		getType(void) const;
};

std::ostream & operator << (std::ostream &out, const WrongAnimal &wronganimal);

#endif