/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:59:31 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 15:00:42 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include <cstring>

#define RED "\033[1;31m"
#define DEFAULT "\033[0m"

int main(int argc, char const *argv[])
{
	Base *base = NULL;
	if (argc == 2 && std::strlen(argv[1]) == 1)
		base = generate(*argv[1]);
	else if (argc == 1)
		base = generate();
	else
	{
		std::cout << RED << "Usage: ./identify [type]" << DEFAULT << std::endl;
		return (1);
	}
	identify(base);
	identify(*base);
}

