/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:21:34 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:29:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_add_active_trap(t_data *data, int x, int y)
{
	data->active_traps[data->rendered_traps] = mlx_texture_to_image(data->mlx,
			data->textures->trap_1);
	if (!data->active_traps[data->rendered_traps])
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx,
			data->active_traps[data->rendered_traps], x, y) < 0)
		return (EXIT_FAILURE);
	data->active_traps[data->rendered_traps]->enabled = 0;
	return (0);
}

int	ft_trap_list(t_data *data, mlx_image_t *image)
{
	if (data->rendered_traps == 0)
	{
		data->total_traps = ft_count('T', data->map);
		data->active_traps = malloc((sizeof(mlx_image_t)
					* data->total_traps) + 1);
		if (!data->active_traps)
			return (0);
		data->inactive_traps = malloc((sizeof(mlx_image_t)
					* data->total_traps) + 1);
		if (!data->inactive_traps)
			return (0);
		data->inactive_traps[0] = image;
		ft_add_active_trap(data, image->instances[0].x, image->instances[0].y);
		data->inactive_traps[data->total_traps] = 0;
		data->active_traps[data->total_traps] = 0;
		data->rendered_traps++;
	}
	else
	{
		data->inactive_traps[data->rendered_traps] = image;
		ft_add_active_trap(data, image->instances[0].x, image->instances[0].y);
		data->rendered_traps++;
	}
	return (1);
}

void	ft_update_traps(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_traps)
	{
		if ((data->frame + (i * 10)) % 75 == 0)
		{
			if (data->active_traps[i]->enabled)
				data->active_traps[i]->enabled = 0;
			else
				data->active_traps[i]->enabled = 1;
			if (data->inactive_traps[i]->enabled)
				data->inactive_traps[i]->enabled = 0;
			else
				data->inactive_traps[i]->enabled = 1;
		}
		i++;
	}
}

void	ft_time(t_data *data)
{
	if (data->frame == 4294967295)
		data->frame = 0;
	data->frame++;
	ft_update_traps(data);
}

void	ft_check_traps(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_traps)
	{
		if (data->inactive_traps[i]->enabled
			&& data->inactive_traps[i]->instances[0].x == data->x * 32
			&& data->inactive_traps[i]->instances[0].y == data->y * 32)
			return ;
		else if (data->active_traps[i]->enabled
			&& data->active_traps[i]->instances[0].x == data->x * 32
			&& data->active_traps[i]->instances[0].y == data->y * 32)
		{
			ft_printf("You lost :c\n");
			mlx_close_window(data->mlx);
		}
		i++;
	}
}
