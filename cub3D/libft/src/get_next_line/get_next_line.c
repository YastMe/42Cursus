/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:40:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/02 12:53:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_readstr(int fd, char *str)
{
	char	*buff;
	int		chars_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	chars_read = 1;
	while (!ft_strchr(str, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[chars_read] = 0;
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining = ft_readstr(fd, remaining);
	if (!remaining)
		return (NULL);
	line = ft_getline(remaining);
	remaining = ft_getremain(remaining);
	return (line);
}
