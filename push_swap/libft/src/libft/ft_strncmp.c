/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:42:02 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *) s1;
	aux2 = (unsigned char *) s2;
	i = 0;
	while ((aux1[i] != '\0' || aux2[i] != '\0') && (i < n))
	{
		if (aux1[i] < aux2[i])
			return (-1);
		if (aux1[i] > aux2[i])
			return (1);
		i++;
	}
	return (0);
}
