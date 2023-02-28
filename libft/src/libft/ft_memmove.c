/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:30:14 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*srcaux;
	char	*dstaux;

	srcaux = (char *)src;
	dstaux = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src < dst)
	{
		while (len--)
			dstaux[len] = srcaux[len];
	}
	else
	{
		while (i < len)
		{
			dstaux[i] = srcaux[i];
			i++;
		}
	}
	return (dst);
}
