/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:14:54 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 16:31:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED "Usage: ./bitcoin [filename]" DEFAULT << std::endl;
		return (1);
	}

	BitcoinExchange	btc = BitcoinExchange();
	btc.processFile(argv[1]);

	return (0);
}
