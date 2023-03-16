/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:00:49 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/15 14:57:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_flood_fill(int x, int y, t_data *data, int *exit)
{
	char	c;

	c = data->map[y][x];
	if (c != '1' && c != 'F')
	{
		if (c == 'E')
			*exit = 1;
		if (c == 'C')
			data->collectibles++;
		data->map[y][x] = 'F';
		if (x + 1 < data->size_x)
			ft_flood_fill(x + 1, y, data, exit);
		if (x - 1 >= 0)
			ft_flood_fill(x - 1, y, data, exit);
		if (y + 1 < data->size_y)
			ft_flood_fill(x, y + 1, data, exit);
		if (y - 1 >= 0)
			ft_flood_fill(x, y - 1, data, exit);
	}
}

int	ft_count(char c, char **map)
{
	int	i;
	int	j;
	int	tot;

	i = 0;
	tot = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				tot++;
			j++;
		}
		i++;
	}
	return (tot);
}

int	ft_rectangle(char **map)
{
	int		i;
	size_t	len;
	size_t	len_pre;

	i = 1;
	len_pre = ft_strlen(map[0]);
	if (map[i][len_pre - 1] == '\n')
			len_pre--;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len_pre != len)
			return (0);
		i++;
		len_pre = len;
	}
	return (1);
}

int	ft_walls(char **map, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size_x)
		if (map[i][j++] != '1')
			return (0);
	j = 0;
	while (i < size_y)
		if (map[i++][j] != '1')
			return (0);
	i = size_y - 1;
	j = 0;
	while (j < size_x)
		if (map[i][j++] != '1')
			return (0);
	i = 0;
	j = size_x - 1;
	while (i < size_y)
		if (map[i++][j] != '1')
			return (0);
	return (1);
}

int	ft_validate(t_data data)
{
	int	exit;
	int	valid_base;

	exit = 0;
	valid_base = (data.size_y >= 3 && data.size_x >= 5
			&& ft_count('E', data.map) == 1
			&& ft_count('P', data.map) == 1
			&& ft_count('C', data.map) >= 1
			&& ft_rectangle(data.map)
			&& ft_walls(data.map, data.size_x, data.size_y));
	if (valid_base)
	{
		ft_flood_fill(data.x, data.y, &data, &exit);
		if (exit && data.collectibles == data.total_collectibles)
			return (1);
	}
	ft_printf("Error.\n");
	return (0);
}
