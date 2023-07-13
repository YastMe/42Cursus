/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:04:14 by abeltran          #+#    #+#             */
/*   Updated: 2023/04/27 12:05:03 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
{
	long	len;
	long	total;
	long	i;

	len = ft_strlen(str);
	while (*str == ' ' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '0' && len == 1)
		return (0);
	total = 0;
	if (*str == '-' || *str == '+')
		i = 1;
	else
		i = 0;
	while (i < len && ft_isdigit(str[i]))
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (*str == '-')
		return (total * -1);
	return (total);
}
