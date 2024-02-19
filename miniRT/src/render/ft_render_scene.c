/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:25:02 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/25 12:38:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static double	ft_distance(t_data *data, t_object *obj, t_vector *dir,
t_vector *origin)
{
	if (obj->type == sphere)
		return (ft_sphere_distance(data, obj, dir, origin));
	else if (obj->type == plane)
		return (ft_plane_distance(data, obj, dir, origin));
	else if (obj->type == cylinder)
		return (ft_cylinder_distance(data, obj, dir, origin));
	return (DBL_MAX);
}

t_object	*ft_closest_obj(t_data *data, t_vector *dir, t_vector *origin)
{
	t_object	*aux;
	double		closest_distance;
	double		current_distance;
	t_object	*closest_obj;

	closest_distance = DBL_MAX;
	aux = data->scene;
	closest_obj = NULL;
	while (aux)
	{
		current_distance = ft_distance(data, aux, dir, origin);
		if (current_distance < closest_distance && current_distance > 1e-6)
		{
			closest_distance = current_distance;
			closest_obj = aux;
		}
		aux = aux->next;
	}
	return (closest_obj);
}

static t_vector	ft_process_objs(t_data *data, t_vector *coord)
{
	t_vector	color;
	t_object	*closest_obj;
	t_vector	dir;

	dir = ft_get_dir(data, coord);
	dir = ft_vector_rotate(&dir, &data->rotation);
	ft_vector_init(&color, data->bgcolor->i,
		data->bgcolor->j, data->bgcolor->k);
	closest_obj = ft_closest_obj(data, &dir, &data->cam.position);
	if (closest_obj)
	{
		if (closest_obj->type == sphere)
			color = ft_intersect_sphere(data, &dir, closest_obj,
					&data->cam.position);
		else if (closest_obj->type == plane)
			color = ft_intersect_plane(data, &dir, closest_obj,
					&data->cam.position);
		else if (closest_obj->type == cylinder)
			color = ft_intersect_cylinder(data, &dir, closest_obj,
					&data->cam.position);
	}
	return (color);
}

void	ft_render_scene(t_data *data)
{
	uint32_t	x;
	uint32_t	y;
	t_vector	color;
	t_vector	coord;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_vector_init(&coord, ((float)x / (float)WIDTH) * 2.0f - 1.0f,
				((float)y / (float)HEIGHT) * 2.0f - 1.0f, 0);
			coord.i *= (WIDTH / (double)HEIGHT);
			color = ft_process_objs(data, &coord);
			color.i = ft_clamp(color.i, 0, 1);
			color.j = ft_clamp(color.j, 0, 1);
			color.k = ft_clamp(color.k, 0, 1);
			mlx_put_pixel(data->canvas, x, y, ft_convert_to_rgba(&color));
			x++;
		}
		y++;
	}
}
