/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:54:30 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:05:19 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiasource);
		~MateriaSource();

		MateriaSource & operator = (const MateriaSource &materiasource);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

std::ostream & operator << (std::ostream &out, const MateriaSource &materiasource);

#endif