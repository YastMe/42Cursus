/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:43:01 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 17:42:15 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		Fixed & operator = (const Fixed &fixed);
};

#endif