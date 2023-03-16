/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:18:51 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/15 14:57:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_count_rows(char *map_file)
{
	int		i;
	char	*row;
	int		fd;

	fd = open(map_file, O_RDONLY);
	i = 0;
	row = get_next_line(fd);
	while (row)
	{
		i++;
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	read_map_file(char *map_file, t_data *data)
{
	char	**map;
	char	*row;
	int		fd;
	int		i;

	i = ft_count_rows(map_file);
	map = (char **) malloc(sizeof(char **) * (i + 1));
	if (!map)
		return ;
	fd = open(map_file, O_RDONLY);
	row = get_next_line(fd);
	data->size_x = ft_strlen(row) - 1;
	data->size_y = i;
	i = 0;
	while (row)
	{
		map[i] = ft_strdup(row);
		i++;
		free(row);
		row = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	free(row);
	data->map = map;
}

void	ft_start_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	data->x = 0;
	data->y = 0;
}

void	ft_collectibles(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				data->total_collectibles++;
			}
			x++;
		}
		y++;
	}
}
