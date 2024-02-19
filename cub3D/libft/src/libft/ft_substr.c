/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:04:14 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (start > ft_strlen(s))
	{
		substr = (char *) malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = 0;
		return (substr);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	substr = (char *) malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		if (i++ >= start && j < len)
			substr[j++] = s[i - 1];
	substr[j] = 0;
	return (substr);
}
