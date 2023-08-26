/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:22 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/11 14:12:45 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Sed.hpp"

int main(int argc, char const *argv[])
{
	if (argc == 4)
	{
		Sed sed(argv[1]);
		sed.replace(argv[2], argv[3]);
	}
	else
		std::cerr << RED << "Usage: ./sed [filename] [s1] [s2]" << std::endl << DEFAULT;
	return 0;
}
