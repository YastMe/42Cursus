/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:20:20 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:27:09 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <list>
# include <iostream>
# include <numeric>
# include <algorithm>

class Span
{
	private:
		unsigned int	_N;
		unsigned int	_size;
		std::list<int>	_list;
	public:
		Span();
		Span(unsigned int max_size);
		Span(const Span &span);
		~Span();
		Span & operator = (const Span &span);

		void			addNumber(int n);
		int				shortestSpan(void);
		int				longestSpan(void);
		int				getN(void) const;
		int				getSize(void) const;
		std::list<int>	getList(void) const;
		void			randomFill(void);
};

std::ostream & operator << (std::ostream &out, const Span &span);
