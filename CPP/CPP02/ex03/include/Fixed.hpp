/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:43:01 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 19:13:50 by abeltran         ###   ########.fr       */
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
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		Fixed & operator = (const Fixed &fixed);

		bool operator > (const Fixed &fixed);
		bool operator < (const Fixed &fixed);
		bool operator >= (const Fixed &fixed);
		bool operator <= (const Fixed &fixed);
		bool operator == (const Fixed &fixed);
		bool operator != (const Fixed &fixed);

		Fixed operator + (const Fixed &fixed);
		Fixed operator - (const Fixed &fixed);
		Fixed operator * (const Fixed &fixed);
		Fixed operator / (const Fixed &fixed);

		Fixed operator - (void);

		Fixed & operator ++ (void);
		Fixed & operator -- (void);
		Fixed operator ++ (int);
		Fixed operator -- (int);

		static Fixed	&min(Fixed &f1, Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

std::ostream & operator << (std::ostream &out, const Fixed &fixed);

#endif