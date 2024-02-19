/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:57:51 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/15 10:56:19 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vector	ft_sp_normal(t_object *sp, t_vector *hit)
{
	t_vector	v;

	ft_vector_init(&v, hit->i - sp->params[0], hit->j - sp->params[1],
		hit->k - sp->params[2]);
	ft_vector_normalize(&v);
	return (v);
}

double	ft_sphere_distance(t_data *data, t_object *sphere, t_vector *dir,
t_vector *origin)
{
	t_vector	co;
	double		*values;
	double		t;

	(void) data;
	ft_vector_init(&co, origin->i - sphere->params[0],
		origin->j - sphere->params[1], origin->k - sphere->params[2]);
	values = ft_solve_equation(ft_dot(dir, dir), 2 * ft_dot(&co, dir),
			ft_dot(&co, &co) - sphere->params[3] / 2 * sphere->params[3] / 2);
	if (!values)
		return (DBL_MAX);
	t = values[0];
	return (free(values), t);
}

t_vector	ft_intersect_sphere(t_data *data, t_vector *dir, t_object *sp,
t_vector *origin)
{
	double		value;
	t_vector	hit_point;

	value = ft_sphere_distance(data, sp, dir, origin);
	ft_vector_init(&hit_point, origin->i + dir->i * value,
		origin->j + dir->j * value, origin->k + dir->k * value);
	return (ft_apply_light(data, sp, &hit_point, ft_sp_normal(sp, &hit_point)));
}
