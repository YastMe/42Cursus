/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:05:16 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_negatives(int n, char *str, int digits)
{
	int	mod;

	while (digits > 0)
	{
		mod = n % 10;
		mod = -mod;
		n = n / 10;
		str[digits] = mod + '0';
		digits--;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_positives(int n, char *str, int digits)
{
	int	mod;

	while (digits >= 0)
	{
		mod = n % 10;
		n = n / 10;
		str[digits] = mod + '0';
		digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_count_digits(n);
	if (n < 0 || n == 0)
		i++;
	str = (char *) malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str = ft_negatives(n, str, i - 1);
	else if (n > 0)
		str = ft_positives(n, str, i - 1);
	else
		str[0] = '0';
	str[i] = 0;
	return (str);
}
