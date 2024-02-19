/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:44:31 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/23 11:59:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	ft_cy_height(t_data *data, t_object *cy, t_vector *dir,
t_vector *origin)
{
	t_vector	v;
	t_vector	vt;
	t_vector	co;
	double		t;
	double		m;

	ft_vector_init(&v, cy->params[3], cy->params[4], cy->params[5]);
	v = ft_vector_normalize(&v);
	ft_vector_init(&co, origin->i - cy->params[0], origin->j - cy->params[1],
		origin->k - cy->params[2]);
	t = ft_cylinder_distance(data, cy, dir, origin);
	vt = ft_vector_scalar(&v, t);
	m = ft_dot(dir, &vt) + ft_dot(&co, &v);
	return (m);
}

t_vector	ft_cy_normal(t_data *data, t_object *cy, t_vector *dir,
t_vector *origin)
{
	double		t;
	double		m;
	t_vector	v;
	t_vector	normal;
	t_vector	hit;

	t = ft_cylinder_distance(data, cy, dir, origin);
	m = ft_cy_height(data, cy, dir, origin);
	ft_vector_init(&v, cy->params[3], cy->params[4], cy->params[5]);
	v = ft_vector_normalize(&v);
	ft_vector_init(&hit, origin->i + dir->i * t,
		origin->j + dir->j * t, origin->k + dir->k * t);
	ft_vector_init(&normal, hit.i - cy->params[0] - v.i * m,
		hit.j - cy->params[1] - v.j * m, hit.k - cy->params[2] - v.k * m);
	return (normal);
}

double	ft_cylinder_distance(t_data *data, t_object *cy, t_vector *dir,
t_vector *origin)
{
	t_vector	v;
	t_vector	vt;
	t_vector	co;
	double		*values;
	double		t;

	(void) data;
	ft_vector_init(&v, cy->params[3], cy->params[4], cy->params[5]);
	v = ft_vector_normalize(&v);
	ft_vector_init(&co, origin->i - cy->params[0], origin->j - cy->params[1],
		origin->k - cy->params[2]);
	values = ft_solve_equation(ft_dot(dir, dir) - (ft_dot(dir, &v)
				* ft_dot(dir, &v)), 2 * (ft_dot(dir, &co) - ft_dot(dir, &v)
				* ft_dot(&co, &v)), ft_dot(&co, &co) - (ft_dot(&co, &v)
				* ft_dot(&co, &v)) - (cy->params[6] / 2) * (cy->params[6] / 2));
	if (!values)
		return (DBL_MAX);
	t = values[0];
	vt = ft_vector_scalar(&v, t);
	if (ft_dot(dir, &vt) + ft_dot(&co, &v) > cy->params[7]
		|| ft_dot(dir, &vt) + ft_dot(&co, &v) < 0)
		return (DBL_MAX);
	return (free(values), t);
}

t_vector	ft_intersect_cylinder(t_data *data, t_vector *dir, t_object *cy,
t_vector *origin)
{
	double		value;
	t_vector	hit_point;

	value = ft_cylinder_distance(data, cy, dir, origin);
	ft_vector_init(&hit_point, origin->i + dir->i * value,
		origin->j + dir->j * value, origin->k + dir->k * value);
	return (ft_apply_light(data, cy, &hit_point,
			ft_cy_normal(data, cy, dir, origin)));
}
