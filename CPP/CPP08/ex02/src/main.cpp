/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:44:30 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 14:04:47 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <list>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

int main()
{
	std::cout << GREEN;
	std::cout << "##########################" << std::endl;
	std::cout << "MutantStack iterator test." << std::endl;
	std::cout << "##########################" << std::endl;
	std::cout << std::endl << DEFAULT;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top item in MutantStack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator MStackItBegin = mstack.begin();
	MutantStack<int>::iterator MStackItEnd = mstack.end();
	++MStackItBegin;
	--MStackItBegin;
	std::cout << "MutantStack contents: ";
	while (MStackItBegin != MStackItEnd)
	{
		std::cout << *MStackItBegin << " ";
		++MStackItBegin;
	}
	
	std::cout << std::endl << std::endl << RED;
	std::cout << "#########################################" << std::endl;
	std::cout << "Trying to copy MutantStack to std::stack." << std::endl;
	std::cout << "#########################################" << std::endl;
	std::stack<int> s(mstack);
	std::cout << std::endl << YELLOW << "If this message prints, then the copy was successful." << std::endl;
	std::cout << DEFAULT;

	std::cout << std::endl;

	std::cout << GREEN;
	std::cout << "########################" << std::endl;
	std::cout << "std::list iterator test." << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << std::endl << DEFAULT;

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Back item in list: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "List size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator listItBegin = list.begin();
	std::list<int>::iterator listItEnd = list.end();
	++listItBegin;
	--listItBegin;
	std::cout << "List contents: ";
	while (listItBegin != listItEnd)
	{
		std::cout << *listItBegin << " ";
		++listItBegin;
	}

	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "###########################################" << std::endl;
	std::cout << "Test cases and outputs should be identical." << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << DEFAULT;
	return (0);
}