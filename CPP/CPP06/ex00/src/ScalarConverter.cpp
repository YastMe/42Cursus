/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:17:04 by abeltran          #+#    #+#             */
/*   Updated: 2024/09/02 19:04:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string &str)
{
	std::cout << std::fixed;

	std::string	specialCases[7] = {
		"-inff",
		"+inff",
		"-inf",
		"+inf",
		"inff",
		"-nanf",
		"-nan"
	};

	std::string	aux = str;
	char		toChar = 0;
	int			toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;
	long double	overflow = 0;
	char		*error;
	bool		overChar = false;
	bool		overInt = false;
	bool		overFloat = false;
	bool		overDouble = false;

	for (int i = 0; i < 7; i++)
	{
		if (str == specialCases[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}

	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	if (aux[aux.length() - 1] == 'f' && aux.length() > 1)
		aux.erase(aux.end() - 1);
	
	overflow = std::strtold(aux.c_str(), &error);
	if (*error != 0)
	{
		std::cout << "Unable to cast input." << std::endl;
		return ;
	}

	if (overflow > 255 || overflow < 0)
		overChar = true;
	if (overflow > INT_MAX || overflow < INT_MIN)
		overInt = true;
	if (overflow > FLOAT_MAX || overflow < FLOAT_MIN)
		overFloat = true;
	if (overflow > DOUBLE_MAX || overflow < DOUBLE_MIN)
		overDouble = true;

	if (str.size() == 1 && std::isprint(aux[0]) && !std::isdigit(aux[0]))
	{
		toChar = aux[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar) << ".0" << std::endl;
		return ;
	}
	
	toInt = std::atoi(aux.c_str());

	if (toChar == 0 && toInt >= '!' && toInt < '~' && !overChar && !overInt)
	{
		toChar = static_cast<char>(toInt);
		std::cout << "char: '" << toChar << "'" << std::endl;
	}
	else
		std::cout << "char: " << RED << "Non displayable." << DEFAULT << std::endl;

	if (!overInt)
	{
		toInt = std::atoi(aux.c_str());
		std::cout << "int: " << toInt << std::endl;
	}
	else
		std::cout << "int: " << RED << "overflow." << DEFAULT << std::endl;

	if (!overFloat)
	{
		toFloat = std::atof(aux.c_str());
		std::cout << "float: " << toFloat;
		std::cout << "f" << std::endl;
	}
	else
		std::cout << "float: " << RED << "overflow." << DEFAULT  << std::endl;

	if (!overDouble)
	{
		toDouble = std::strtod(aux.c_str(), &error);
		if (*error != 0)
			std::cout << RED << "Error parsing double." << DEFAULT << std::endl;
		else
			std::cout << "double: " << toDouble;
		std::cout << std::endl;
	}
	else
		std::cout << "double: " << RED << "overflow." << DEFAULT  << std::endl;
}
