/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:18 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:44:49 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_up(t_data *data)
{
	int	i;

	i = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && data->y - 1 >= 0)
	{
		if (data->map[data->y - 1][data->x] != '1')
		{
			while (i < 4)
			{
				data->anim_image_frames[i]->instances[0].y -= 32;
				data->anim_image_frames[i]->enabled = 0;
				i++;
			}
			data->anim_image_frames[0]->enabled = 1;
			data->character->instances[0].y -= 32;
			data->y -= 1;
			data->moves++;
			data->key_pressed = 1;
		}
	}
}

void	move_down(t_data *data)
{
	int	i;

	i = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		&& data->character->instances[0].y < data->mlx->height - 32
		&& data->y + 1 < data->size_y)
	{
		if (data->map[data->y + 1][data->x] != '1')
		{
			while (i < 4)
			{
				data->anim_image_frames[i]->instances[0].y += 32;
				data->anim_image_frames[i]->enabled = 0;
				i++;
			}
			data->anim_image_frames[1]->enabled = 1;
			data->character->instances[0].y += 32;
			data->y += 1;
			data->moves++;
			data->key_pressed = 1;
		}
	}
}

void	move_left(t_data *data)
{
	int	i;

	i = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		&& data->character->instances[0].x > 0 && data->x - 1 >= 0)
	{
		if (data->map[data->y][data->x - 1] != '1')
		{
			while (i < 4)
			{
				data->anim_image_frames[i]->instances[0].x -= 32;
				data->anim_image_frames[i]->enabled = 0;
				i++;
			}
			data->anim_image_frames[2]->enabled = 1;
			data->character->instances[0].x -= 32;
			data->x -= 1;
			data->moves++;
			data->key_pressed = 1;
		}
	}
}

void	move_right(t_data *data)
{
	int	i;

	i = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		&& data->character->instances[0].x < data->mlx->width - 32
		&& data->x + 1 < data->size_x)
	{
		if (data->map[data->y][data->x + 1] != '1')
		{
			while (i < 4)
			{
				data->anim_image_frames[i]->instances[0].x += 32;
				data->anim_image_frames[i]->enabled = 0;
				i++;
			}
			data->anim_image_frames[3]->enabled = 1;
			data->character->instances[0].x += 32;
			data->x += 1;
			data->moves++;
			data->key_pressed = 1;
		}
	}
}

void	ft_update(void *param)
{
	t_data	*data;

	data = param;
	if (!data->key_pressed)
	{
		move_up(data);
		move_down(data);
		move_left(data);
		move_right(data);
	}
	else if (!mlx_is_key_down(data->mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		ft_check_collectibles(data);
		ft_check_end(data);
		data->key_pressed = 0;
		ft_render_moves(data);
	}
	ft_time(data);
	ft_check_traps(data);
	ft_exit_program(data);
}
