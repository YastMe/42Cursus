/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:16:36 by abeltran          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:55 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list arg, char format);
int		ft_putchar(int c);
int		ft_putstr(char	*s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, char format);
int		ft_putptr(__UINTPTR_TYPE__ n);

#endif
