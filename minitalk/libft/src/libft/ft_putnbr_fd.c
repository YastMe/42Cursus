/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:06:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_printnbr_fd(int n, int fd)
{
	int		mod;
	char	c;

	if (n != 0)
	{
		mod = n % 10;
		if (mod < 0)
			mod = -mod;
		n = n / 10;
		ft_printnbr_fd(n, fd);
		c = mod + '0';
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	ft_printnbr_fd(n, fd);
}
