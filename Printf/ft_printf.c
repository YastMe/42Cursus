/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:13:55 by abeltran          #+#    #+#             */
/*   Updated: 2022/10/16 16:15:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (format == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		i = ft_putptr(va_arg(arg, __UINTPTR_TYPE__));
	else if (format == 'd' || format == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		i = ft_putunbr(va_arg(arg, unsigned int));
	else if (format == 'x')
		i = ft_puthex(va_arg(arg, unsigned int), 'a');
	else if (format == 'X')
		i = ft_puthex(va_arg(arg, unsigned int), 'A');
	else if (format == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		c;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			c += ft_format(args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			c++;
		}
		i++;
	}
	va_end(args);
	return (c);
}

// #include <stdio.h>

// int main()
// {
// 	char res[] = "";
// 	printf(" len %d\n", ft_printf("%p", res));
// 	printf(" len %d\n", printf("%p", res));
// 	printf("Size %lu\n", sizeof(long unsigned int));
// 	return 0;
// }
