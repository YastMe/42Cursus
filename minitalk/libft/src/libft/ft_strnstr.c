/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:05:16 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlen;

	if (*needle == 0 || haystack == needle)
		return ((char *) haystack);
	needlen = ft_strlen(needle);
	i = needlen;
	while (*haystack && i <= len)
	{
		if (!(ft_strncmp(haystack, needle, needlen)))
			return ((char *) haystack);
		haystack++;
		i++;
	}
	return (0);
}
