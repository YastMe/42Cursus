/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:15:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/21 17:50:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	rotate_mouse(t_data *data)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x != WIDTH / 2 && data->mouse_x == 0)
		data->mouse_x = x;
	if (x < data->mouse_x)
	{
		data->player.rot_speed = data->mlx->delta_time * (data->mouse_x - x)
			* 0.1f;
		ft_rotate_right(&data->player);
	}
	else if (x > data->mouse_x)
	{
		data->player.rot_speed = data->mlx->delta_time * (x - data->mouse_x)
			* 0.1f;
		ft_rotate_left(&data->player);
	}
	mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_get_mouse_pos(data->mlx, &x, &y);
	data->mouse_x = x;
}

static void	player_minimap(t_data *data)
{
	data->mapplayer->instances[0].x = (int)(data->player.pos.x) * 8;
	data->mapplayer->instances[0].y = (int)(data->player.pos.y) * 8;
}

void	ft_main_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_clear_screen(data);
	ft_movement(data);
	ft_render(data);
	if (data->spin)
		data->timer_spin += data->mlx->delta_time;
	else
	{
		data->timer_spin = 0;
		data->anim.selected = -1;
	}
	if (data->spin && data->timer_spin >= 3)
	{
		if (data->anim.selected == -1)
			data->anim.selected = rand() % 3;
		ft_anim_spin(data);
	}
	rotate_mouse(data);
	player_minimap(data);
}
