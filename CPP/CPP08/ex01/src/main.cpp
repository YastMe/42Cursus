/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:27:52 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:45:00 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main(void)
{
	Span baseSpan = Span(5);
	baseSpan.addNumber(6);
	baseSpan.addNumber(3);
	baseSpan.addNumber(17);
	baseSpan.addNumber(9);
	baseSpan.addNumber(11);
	std::cout << "Span: " << baseSpan << std::endl;
	std::cout << "Shortest span: " << baseSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << baseSpan.longestSpan() << std::endl;

	Span longSpan = Span(100);
	longSpan.randomFill();
	std::cout << "Generated Span with 100 numbers: " << longSpan << std::endl;
	std::cout << "Shortest span: " << longSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << longSpan.longestSpan() << std::endl;

	Span overSpan = Span(5);
	overSpan.randomFill();
	std::cout << "Generated Span with 5 numbers: " << overSpan << std::endl;
	std::cout << "Adding one more number than the capacity of the Span" << std::endl;
	overSpan.addNumber(1);

	Span smallSpan = Span(1);
	smallSpan.addNumber(1);
	std::cout << "Generated Span with 1 number: " << smallSpan << std::endl;
	std::cout << "Trying to get the shortest and longest span of a Span with only one number." << std::endl;
	std::cout << "Shortest span: ";
	smallSpan.shortestSpan();
	std::cout << std::endl << "Longest span: ";
	smallSpan.longestSpan();
	std::cout << std::endl;

	return (0);
}

