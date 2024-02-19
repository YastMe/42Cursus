/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:29:04 by abeltran          #+#    #+#             */
/*   Updated: 2023/09/06 13:38:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static double	decimal_part(const char *str)
{
	int		divider;
	int		i;
	double	total;
	double	decimal;

	divider = 10;
	i = 1;
	total = 0;
	if (*str != '.')
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		decimal = (str[i] - '0');
		total += decimal / divider;
		i++;
		divider *= 10;
	}
	return (total);
}

double	ft_atod(const char *str)
{
	double	len;
	double	total;
	int		i;

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
	total += decimal_part(&str[i]);
	if (*str == '-')
		return (total * -1);
	return (total);
}
