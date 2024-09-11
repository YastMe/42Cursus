/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:09:38 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/05 11:23:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/templates.hpp"
#include <iostream>

int main( void ) {
	// Tests from subject.
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	// My tests.
	std::cout << "Testing for int: " << std::endl;
	::test(8, 54);
	std::cout << "Testing for float: " << std::endl;
	::test(8.8f, 5.4f);
	std::cout << "Testing for double: " << std::endl;
	::test(8.8, 5.4);
	std::cout << "Testing for char: " << std::endl;
	::test('a', 'z');
	std::cout << "Testing for string: " << std::endl;
	::test("aaa", "zzz");
	std::cout << "Testing for bool: " << std::endl;
	::test(true, false);
}