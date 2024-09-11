/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:36:06 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 17:38:23 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn) {*this = rpn;}

RPN::~RPN() {}

RPN & RPN::operator = (const RPN &rpn)
{
	if (this != &rpn)
	{
		_stack = rpn._stack;
	}
	return (*this);
}

/**
 * Private methods 
 */

int RPN::_topAndPop(void)
{
	int top = _stack.top();
	_stack.pop();
	return (top);
}

/**
 * Public methods
 */

void	RPN::calculate(const std::string &str)
{
	int	first_operand;
	int	second_operand;

	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isspace(str[i]))
			continue ;
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
			&& !isdigit(str[i]))
		{
			std::cout << RED << "Error" << DEFAULT << std::endl;
			return ;
		}
		if (isdigit(str[i]))
			_stack.push((int) str[i] - '0');
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (_stack.size() < 2)
			{
				std::cout << RED << "Error" << DEFAULT << std::endl;
				return ;
			}
			second_operand = _topAndPop();
			first_operand = _topAndPop();
			switch (str[i])
			{
				case '+':
					_stack.push(first_operand + second_operand);
					break;
				case '-':
					_stack.push(first_operand - second_operand);
					break;
				case '*':
					_stack.push(first_operand * second_operand);
					break;
				case '/':
					_stack.push(first_operand / second_operand);
					break;
				default:
					break;
			}
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << RED << "Error" << DEFAULT << std::endl;
		return ;
	}
	std::cout << GREEN << _topAndPop() << DEFAULT << std::endl;
}

