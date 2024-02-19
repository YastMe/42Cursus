/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:54:48 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/16 15:37:20 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	ft_up(t_player *p, char **map)
{
	if (map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * p->move_speed)] == '0')
		p->pos.x += p->dir.x * p->move_speed;
	if (map[(int)(p->pos.y + p->dir.y * p->move_speed)][(int)p->pos.x] == '0')
		p->pos.y += p->dir.y * p->move_speed;
}

static void	ft_down(t_player *p, char **map)
{
	if (map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * p->move_speed)] == '0')
		p->pos.x -= p->dir.x * p->move_speed;
	if (map[(int)(p->pos.y - p->dir.y * p->move_speed)][(int)p->pos.x] == '0')
		p->pos.y -= p->dir.y * p->move_speed;
}

static void	ft_right(t_player *p, char **map)
{
	if (map[(int)p->pos.y][(int)(p->pos.x + p->plane.x * p->move_speed)] == '0')
		p->pos.x += p->plane.x * p->move_speed;
	if (map[(int)(p->pos.y + p->plane.y * p->move_speed)][(int)p->pos.x] == '0')
		p->pos.y += p->plane.y * p->move_speed;
}

static void	ft_left(t_player *p, char **map)
{
	if (map[(int)p->pos.y][(int)(p->pos.x - p->plane.x * p->move_speed)] == '0')
		p->pos.x -= p->plane.x * p->move_speed;
	if (map[(int)(p->pos.y - p->plane.y * p->move_speed)][(int)p->pos.x] == '0')
		p->pos.y -= p->plane.y * p->move_speed;
}

void	ft_movement(t_data *data)
{
	data->player.move_speed = data->mlx->delta_time * 5.0;
	data->player.rot_speed = data->mlx->delta_time * 3.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_exit(data, EXIT_SUCCESS);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_up(&data->player, data->map);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_down(&data->player, data->map);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_right(&data->player, data->map);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_left(&data->player, data->map);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_rotate_left(&data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_rotate_right(&data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->spin = true;
	else if (!mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		&& !mlx_is_key_down(data->mlx, MLX_KEY_LEFT) && data->spin)
	{
		ft_disable_anims(data);
		data->spin = false;
	}
}
