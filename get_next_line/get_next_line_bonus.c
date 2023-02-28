/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:40:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/27 17:18:53 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining[fd] = ft_readstr(fd, remaining[fd]);
	if (!remaining[fd])
		return (NULL);
	line = ft_getline(remaining[fd]);
	remaining[fd] = ft_getremain(remaining[fd]);
	return (line);
}