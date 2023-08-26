/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:42:59 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 19:21:20 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include "bsp.cpp"

int main(void) {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point pointInside(2, 2);
	Point pointOutside(10, 10);

	if (!bsp(a, b, c, pointInside))
		std::cout << "Point " << pointInside << " is not inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;
	else
		std::cout << "Point " << pointInside << " is inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;

	if (!bsp(a, b, c, pointOutside))
		std::cout << "Point " << pointOutside << " is not inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;
	else
		std::cout << "Point " << pointOutside << " is inside the triangle [" << a << "," << b << "," << c << "]." << std::endl;

	return (0);
}
