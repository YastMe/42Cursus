/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:48:05 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/20 22:20:03 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	*ft_player_coords(char **map)
{
	int	x;
	int	y;
	int	*coords;

	coords = malloc(sizeof(int) * 3);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				coords[0] = x;
				coords[1] = y;
				coords[2] = map[y][x];
				return (coords);
			}
			x++;
		}
		y++;
	}
	free(coords);
	return (NULL);
}

void	ft_set_rotation(t_data *data, int *coords)
{
	if (coords[2] == 'N')
	{
		data->player.dir.y = -1;
		data->player.plane.x = 0.66;
	}
	else if (coords[2] == 'W')
	{
		data->player.dir.x = -1;
		data->player.plane.y = -0.66;
	}
	else if (coords[2] == 'S')
	{
		data->player.dir.y = 1;
		data->player.plane.x = -0.66;
	}
	else if (coords[2] == 'E')
	{
		data->player.dir.x = 1;
		data->player.plane.y = 0.66;
	}
}

void	ft_set_position(t_data *data, int *coords)
{
	if (!coords)
		ft_error(data, ERR_CUSTOM, "No player found.");
	data->player.pos.x = coords[0] + 0.5;
	data->player.pos.y = coords[1] + 0.5;
	data->map[coords[1]][coords[0]] = '0';
	if (coords[2] == 'N' || coords[2] == 'S')
	{
		data->player.dir.x = 0;
		data->player.plane.y = 0;
	}
	else
	{
		data->player.dir.y = 0;
		data->player.plane.x = 0;
	}
	ft_set_rotation(data, coords);
	free(coords);
}
