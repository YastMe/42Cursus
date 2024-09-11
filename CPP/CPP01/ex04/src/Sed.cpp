/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:06:51 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:59:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

Sed::Sed(std::string filename)
{
	_filename = filename;
}

Sed::~Sed()
{
	std::cout << "Has bebido awita y ya no hay Sed." << std::endl;
}

std::string	changeString(int pos, std::string str, std::string s1, std::string s2)
{
	while ((pos = str.find(s1, pos)) > -1)
	{
		if (pos >= 0)
		{
			str.erase(pos, std::strlen(s1.c_str()));
			str.insert(pos, s2);
			pos += std::strlen(s2.c_str());
		}
	}
	return (str);
}

void	Sed::replace(std::string s1, std::string s2)
{
	std::string	str;

	std::ifstream file_in;
	std::ofstream file_out;
	file_in.open(_filename);
	file_out.open(_filename + ".replace");
	if (file_in.is_open() && file_out.is_open())
	{
		while (std::getline(file_in, str))
		{
			str = changeString(0, str, s1, s2);
			file_out << str << std::endl;
		}
		file_in.close();
		file_out.close();
	}
	else
		std::cerr << Yellow << "Couldn't open file." << DEFAULT << std::endl;
}
