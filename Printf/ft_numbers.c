/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:10 by abeltran          #+#    #+#             */
/*   Updated: 2022/10/16 16:18:51 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	if (!str)
		return (0);
	i = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_utoa(n);
	if (!str)
		return (0);
	i = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (i);
}
