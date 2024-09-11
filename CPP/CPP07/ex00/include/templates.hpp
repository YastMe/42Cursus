/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:11:37 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/05 11:21:18 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
void	test(T a, T b)
{
	std::cout << "a: " << a << " // b: " << b << std::endl;
	::swap(a, b);
	std::cout << "Swap!" << std::endl;
	std::cout << "a: " << a << " // b: " << b << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;
}
