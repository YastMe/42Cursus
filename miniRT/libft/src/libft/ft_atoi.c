/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:29:04 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:47:17 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *str)
{
	int	len;
	int	total;
	int	i;

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
