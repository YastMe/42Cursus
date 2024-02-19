/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:58:39 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/16 13:37:59 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static uint32_t	reversecolor(unsigned int color)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = color << 24 >> 24;
	green = color << 16 >> 24;
	blue = color << 8 >> 24;
	alpha = color >> 24;
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

void	ft_choose_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 1 && ray->dir.y > 0)
	{
		ray->tex = data->n_wall;
		ray->ptex = data->pn_wall;
	}
	if (ray->side == 1 && ray->dir.y < 0)
	{
		ray->tex = data->s_wall;
		ray->ptex = data->ps_wall;
	}
	if (ray->side == 0 && ray->dir.x > 0)
	{
		ray->tex = data->w_wall;
		ray->ptex = data->pw_wall;
	}
	if (ray->side == 0 && ray->dir.x < 0)
	{
		ray->tex = data->e_wall;
		ray->ptex = data->pe_wall;
	}
}

void	ft_get_texture_x(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = data->player.pos.y + ray->p_wall_dist * ray->dir.y;
	else
		ray->wallx = data->player.pos.x + ray->p_wall_dist * ray->dir.x;
	ray->wallx -= floor(ray->wallx);
	ray->tex_x = (int)(ray->wallx * (double)ray->tex->width);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->tex_x = ray->tex->width - ray->tex_x - 1;
}

void	ft_draw_tline(t_data *data, int x, t_ray ray)
{
	double		step;
	double		tex_pos;
	int			y;
	int			tex_y;
	uint32_t	color;

	step = 1.0 * ray.tex->height / ray.l_height;
	tex_pos = (ray.draw_start - data->height / 2 + ray.l_height / 2) * step;
	y = ray.draw_start;
	while (y < ray.draw_end)
	{
		tex_y = (int)tex_pos & (ray.tex->height - 1);
		tex_pos += step;
		color = ray.ptex[(ray.tex_x + ray.tex->height * tex_y)];
		color = reversecolor(color);
		mlx_put_pixel(data->image, x, y, color);
		y++;
	}
}
