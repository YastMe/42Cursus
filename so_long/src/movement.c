/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:13:18 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 15:31:32 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) && data->y - 1 >= 0)
	{
		if (data->map[data->y - 1][data->x] != '1')
		{
			data->character->instances[0].y -= 32;
			data->y -= 1;
			data->moves++;
			ft_printf("Moves: %d\n", data->moves);
			data->key_pressed = 1;
		}
	}
}

void	move_down(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		&& data->character->instances[0].y < data->mlx->height - 32
		&& data->y + 1 < data->size_y)
	{
		if (data->map[data->y + 1][data->x] != '1')
		{
			data->character->instances[0].y += 32;
			data->y += 1;
			data->moves++;
			ft_printf("Moves: %d\n", data->moves);
			data->key_pressed = 1;
		}
	}
}

void	move_left(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		&& data->character->instances[0].x > 0 && data->x - 1 >= 0)
	{
		if (data->map[data->y][data->x - 1] != '1')
		{
			data->character->instances[0].x -= 32;
			data->x -= 1;
			data->moves++;
			ft_printf("Moves: %d\n", data->moves);
			data->key_pressed = 1;
		}
	}
}

void	move_right(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		&& data->character->instances[0].x < data->mlx->width - 32
		&& data->x + 1 < data->size_x)
	{
		if (data->map[data->y][data->x + 1] != '1')
		{
			data->character->instances[0].x += 32;
			data->x += 1;
			data->moves++;
			ft_printf("Moves: %d\n", data->moves);
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
		data->key_pressed = 0;
	if (data->map[data->y][data->x] == 'C' && !data->key_pressed)
		ft_check_collectibles(data);
	if (data->map[data->y][data->x] == 'E' && data->key_pressed)
		ft_check_end(data);
	ft_exit_program(data);
}
