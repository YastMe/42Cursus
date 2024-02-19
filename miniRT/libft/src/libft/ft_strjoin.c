/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:07:40 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*str;
	size_t		i;
	size_t		slen;

	len = ft_strlen(s1) + ft_strlen(s2);
	slen = ft_strlen(s1);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < slen)
			str[i] = s1[i];
		else
			str[i] = s2[i - slen];
		i++;
	}
	str[i] = 0;
	return (str);
}
