/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:20:20 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 18:36:10 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <list>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[33m"
# define DEFAULT "\033[0m"

static long int get_time()
{
	struct timeval	tv;
	long int		useconds;
	
	gettimeofday(&tv, NULL);
	useconds = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (useconds);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << RED << "Usage: ./PmergeMe [-p] [int1 int2 int3 ...]" << DEFAULT << std::endl;
		return (1);
	}

	bool print = false;

	if (std::string(argv[1]) == "-p")
	{
		print = true;
		argv++;
	}
	
	PmergeMe			merge(&argv[1]);
	std::vector<int>	v = merge.getVector();
	std::list<int>		l = merge.getList();

	long int			start_time;
	long int			vector_time;
	long int			list_time;

	start_time = get_time();
	v = merge.vectorSort(v);
	vector_time = get_time() - start_time;

	start_time = get_time();
	l = merge.listSort(l);
	list_time = get_time() - start_time;

	if (print)
	{
		std::cout << ORANGE << "std::vector values before sorting: " << merge.getVector() << DEFAULT << std::endl;
		std::cout << ORANGE << "std::vector values after sorting: " << v << DEFAULT << std::endl;
		std::cout << ORANGE << "std::list values before sorting: " << merge.getList() << DEFAULT << std::endl;
		std::cout << ORANGE << "std::list values after sorting: " << l << DEFAULT << std::endl;
	}
	std::cout << GREEN << "std::vector: " << vector_time << " microseconds" << DEFAULT << std::endl;
	std::cout << GREEN << "std::list: " << list_time << " microseconds" << DEFAULT << std::endl;
	return (0);
}
