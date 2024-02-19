/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:34:47 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/16 12:36:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_get_draw_points(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->p_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->p_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->l_height = (int)(data->height / ray->p_wall_dist);
	ray->draw_start = -ray->l_height / 2 + data->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->l_height / 2 + data->height / 2;
	if (ray->draw_end >= data->height)
		ray->draw_end = data->height - 1;
}

void	ft_perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (data->map[ray->map.y][ray->map.x] != '0')
			ray->hit = 1;
	}
}

static void	ft_calc_step(t_data *data, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data->player.pos.x - ray->map.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - data->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data->player.pos.y - ray->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - data->player.pos.y)
			* ray->delta_dist.y;
	}
}

void	ft_init_ray(t_data *data, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (float)data->width - 1;
	ray->dir.x = data->player.dir.x + data->player.plane.x * ray->cam_x;
	ray->dir.y = data->player.dir.y + data->player.plane.y * ray->cam_x;
	ray->map.x = (int)data->player.pos.x;
	ray->map.y = (int)data->player.pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabsf(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabsf(1 / ray->dir.y);
	ray->hit = 0;
	ft_calc_step(data, ray);
}
