/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:31:23 by abeltran          #+#    #+#             */
/*   Updated: 2024/07/23 13:09:49 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;

	switch (random)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	default:
		return (NULL);
		break;
	}
}

Base *generate(char type)
{
	switch (std::tolower(type))
	{
	case 'a':
		return (new A);
		break;
	case 'b':
		return (new B);
		break;
	case 'c':
		return (new C);
		break;
	default:
		return (NULL);
		break;
	}

}
void identify(Base *p)
{
	std::cout << "Identifying object type from pointer." << std::endl;

	std::cout << "Object type: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Not recognized.";
	std::cout << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identifying object type from copy." << std::endl;

	std::cout << "Object type: ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A";
		(void) a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B";
			(void) b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C";
				(void) c;
			}
			catch (std::exception &e)
			{
				std::cout << "Not recognized.";
			}
		}
	}
	std::cout << std::endl;
}
