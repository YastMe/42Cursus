/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:33:29 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/21 16:40:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define DEFAULT "\033[0m"

class RPN
{
	private:
		std::stack<int>	_stack;
		int				_topAndPop(void);
	public:
		RPN();
		RPN(const RPN &rpn);
		~RPN();
		RPN & operator = (const RPN &rpn);
		void calculate(const std::string &str);
};

#endif