/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:02:36 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:49:54 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_printhex(unsigned int n, char *base)
{
	if (n > 15)
		ft_printhex(n / 16, base);
	ft_putchar(base[n % 16]);
}

int	ft_hexlen(long unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

int	ft_puthex(unsigned int n, char format)
{
	char	*base;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (format == 'a')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_printhex(n, base);
	return (ft_hexlen(n));
}

void	ft_printhexptr(long unsigned int n, char *base, int nn)
{
	if (nn > 0)
	{
		if (n > 15)
			ft_printhexptr(n / 16, base, nn - 1);
		ft_putchar(base[n % 16]);
	}
}

int	ft_putptr(__UINTPTR_TYPE__ n)
{
	ft_putstr("0x");
	if (n == 0)
	{
		ft_putchar('0');
		return (3);
	}
	ft_printhexptr(n, "0123456789abcdef", 16);
	return (ft_hexlen(n) + 2);
}
