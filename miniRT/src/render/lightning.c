/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:16:09 by abeltran          #+#    #+#             */
/*   Updated: 2023/11/25 12:34:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_apply_final_lights(t_data *data, t_vector *color, double intensity)
{
	color->i *= intensity
		+ (data->ambient->params[0] * data->ambient->color->i);
	color->j *= intensity
		+ (data->ambient->params[0] * data->ambient->color->j);
	color->k *= intensity
		+ (data->ambient->params[0] * data->ambient->color->k);
}

t_vector	ft_apply_light(t_data *data, t_object *obj, t_vector *hit,
t_vector normal)
{
	t_vector	l_dir;
	double		intensity;
	t_vector	color;
	t_object	*lights;
	t_object	*aux;

	lights = data->lights;
	intensity = 0;
	ft_vector_init(&color, obj->color->i, obj->color->j, obj->color->k);
	while (lights)
	{
		if (lights->type == light)
		{
			ft_vector_init(&l_dir, lights->params[0] - hit->i,
				lights->params[1] - hit->j, lights->params[2] - hit->k);
			l_dir = ft_vector_normalize(&l_dir);
			aux = ft_closest_obj(data, &l_dir, hit);
			if (!aux || aux == obj)
				intensity += ft_max(ft_dot(&normal, &l_dir), 0)
					* lights->params[3];
		}
		lights = lights->next;
	}
	ft_apply_final_lights(data, &color, intensity);
	return (color);
}
