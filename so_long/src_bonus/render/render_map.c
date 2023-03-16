/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:44 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:26 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_disable_exits(t_data *data)
{
	data->exit_images[0]->enabled = 1;
	data->exit_images[1]->enabled = 0;
	data->exit_images[2]->enabled = 0;
	data->exit_images[3]->enabled = 0;
	data->exit_images[4]->enabled = 0;
}

void	ft_render_exits(int i, int j, t_data *data)
{
	data->exit_images = malloc(sizeof(mlx_image_t *) * 5);
	if (!data->exit_images)
		return ;
	data->exit_images[0] = mlx_texture_to_image(data->mlx,
			data->textures->exit_empty);
	data->exit_images[1] = mlx_texture_to_image(data->mlx,
			data->textures->exit_1);
	data->exit_images[2] = mlx_texture_to_image(data->mlx,
			data->textures->exit_2);
	data->exit_images[3] = mlx_texture_to_image(data->mlx,
			data->textures->exit_3);
	data->exit_images[4] = mlx_texture_to_image(data->mlx,
			data->textures->exit_4);
	if (mlx_image_to_window(data->mlx, data->exit_images[0],
			j * 32, i * 32) < 0
		|| mlx_image_to_window(data->mlx, data->exit_images[1],
			j * 32, i * 32) < 0
		|| mlx_image_to_window(data->mlx, data->exit_images[2],
			j * 32, i * 32) < 0
		|| mlx_image_to_window(data->mlx, data->exit_images[3],
			j * 32, i * 32) < 0
		|| mlx_image_to_window(data->mlx, data->exit_images[4],
			j * 32, i * 32) < 0)
		return ;
	ft_disable_exits(data);
}

int	ft_fill_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_render_sprite(i, j, data, data->textures->ground);
			if (data->map[i][j] == '1')
				ft_render_sprite(i, j, data, data->textures->water);
			else if (data->map[i][j] == 'C')
				ft_render_sprite(i, j, data, data->textures->coffee);
			else if (data->map[i][j] == 'T')
				ft_render_sprite(i, j, data, data->textures->trap_0);
			else if (data->map[i][j] == 'E')
				ft_render_exits(i, j, data);
			j++;
		}
		i++;
	}
	return (0);
}
