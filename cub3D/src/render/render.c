/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:46:30 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/20 21:54:24 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	ft_draw_sky(t_data *data)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < data->height / 2)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_pixel(data->image, x, y, data->sky);
			x++;
		}
		y++;
	}
}

static void	ft_draw_floor(t_data *data)
{
	int32_t	x;
	int32_t	y;

	y = data->height / 2;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_pixel(data->image, x, y, data->floor);
			x++;
		}
		y++;
	}
}

void	ft_render(t_data *data)
{
	int		x;
	t_ray	ray;

	ft_draw_sky(data);
	ft_draw_floor(data);
	x = 0;
	while (x < data->width)
	{
		ft_init_ray(data, &ray, x);
		ft_perform_dda(data, &ray);
		ft_get_draw_points(data, &ray);
		ft_choose_texture(data, &ray);
		ft_get_texture_x(data, &ray);
		ft_draw_tline(data, x, ray);
		x++;
	}
}
