/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:42:59 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/25 21:21:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void ) {
	std::srand(std::time(NULL));
	std::cout << rand()%10+1;
	std::cout << rand()%10+1;
	std::cout << rand()%10+1;
	std::cout << rand()%10+1;
	std::cout << rand()%10+1;
	std::cout << rand()%10+1;
	return (0);
}
