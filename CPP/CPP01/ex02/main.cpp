/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:58:45 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/11 13:09:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "Memory address of str:\t\t" << &str
		<< std::endl << "Memory address inside strPTR:\t" << stringPTR
		<< std::endl << "Memory address inside strREF:\t" << &stringREF
		<< std::endl;
	std::cout << "str value:\t\t\t" << str
		<< std::endl << "strPTR stored value:\t\t" << *stringPTR
		<< std::endl << "strREF stored value:\t\t" << stringREF
		<< std::endl;
	return (0);
}
