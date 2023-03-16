/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:43 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 13:27:56 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_exit_program(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

void	ft_check_end(t_data *data)
{
	if (data->map[data->y][data->x] == 'E')
	{
		if (!data->collectibles)
		{
			mlx_close_window(data->mlx);
			ft_printf("You won!\n");
		}
		else
			ft_printf("There's still collectibles to find!\n");
	}
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	free(data->map);
}

void	ft_finish(t_data *data)
{
	free(data->collectible_images);
	if (ft_count('T', data->map))
	{
		free(data->active_traps);
		free(data->inactive_traps);
	}
	free(data->exit_images);
	free(data->anim_image_frames);
	free(data->anim_texture_frames);
	ft_free_map(data);
	mlx_terminate(data->mlx);
}
