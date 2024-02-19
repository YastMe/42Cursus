/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:37:16 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:42:42 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();

		Brain & operator = (const Brain &brain);

		bool		addIdea(std::string idea);
		std::string	getIdea(int	i);
};

std::ostream & operator << (std::ostream &out, const Brain &brain);

#endif