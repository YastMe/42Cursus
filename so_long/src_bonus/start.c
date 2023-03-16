/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:25:38 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:36:22 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_print_data(t_data *data)
{
	int	i;

	ft_printf("Data:\n  Pos: %d,%d\n  Size: %d*%d\n\n",
		data->x, data->y, data->size_x, data->size_y);
	i = 0;
	while (data->map[i])
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_init(t_data *data)
{
	data->character = NULL;
	data->collectibles = 0;
	data->total_collectibles = 0;
	data->end = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->moves = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->textures = NULL;
	data->x = 0;
	data->y = 0;
	data->key_pressed = 0;
	data->collectible_images = NULL;
	data->exit_images = NULL;
	data->total_traps = 0;
	data->rendered_traps = 0;
}

int	ft_weird_characters(char **map, int size_x, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'T' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_start(char *file)
{
	t_data	data;

	ft_init(&data);
	read_map_file(file, &data);
	ft_collectibles(&data);
	ft_start_pos(&data);
	if (!ft_weird_characters(data.map, data.size_x, data.size_y)
		&& ft_validate(data))
	{
		ft_free_map(&data);
		read_map_file(file, &data);
		data.mlx = mlx_init(data.size_x * 32, data.size_y * 32,
				"so_long", false);
		if (!data.mlx)
			return (EXIT_FAILURE);
		mlx_loop_hook(data.mlx, &ft_update, &data);
		ft_render(&data);
		mlx_loop(data.mlx);
		ft_finish(&data);
		return (EXIT_SUCCESS);
	}
	ft_free_map(&data);
	ft_printf("Unplayable map.\n");
	return (EXIT_FAILURE);
}
