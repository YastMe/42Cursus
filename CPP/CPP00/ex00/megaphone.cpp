/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:53:32 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/02 16:06:42 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
				std::cout << (char) std::toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
