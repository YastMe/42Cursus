/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:38 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 15:41:19 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_gnl(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *full_str, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!full_str)
	{
		full_str = (char *) malloc(sizeof(char));
		full_str[0] = 0;
	}
	if (!full_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_gnl(full_str)
				+ ft_strlen_gnl(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (full_str)
		while (full_str[++i] != 0)
			str[i] = full_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen_gnl(full_str) + ft_strlen_gnl(buff)] = 0;
	free(full_str);
	return (str);
}

char	*ft_getline(char *full_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!*full_str)
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	str = (char *) malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		str[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		str[i] = full_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_getremain(char *full_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
	{
		free(full_str);
		return (NULL);
	}
	str = malloc(ft_strlen_gnl(full_str) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (full_str[i])
		str[j++] = full_str[i++];
	str[j] = 0;
	free(full_str);
	return (str);
}
