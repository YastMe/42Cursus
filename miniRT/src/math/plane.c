/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:27:02 by abeltran          #+#    #+#             */
/*   Updated: 2023/11/15 16:55:29 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/*
static void	ft_init_vectors(t_object *plane, t_vector *point, t_vector *normal)
{
	point->i = plane->params[0];
	point->j = plane->params[1];
	point->k = plane->params[2];
	normal->i = plane->params[3];
	normal->j = plane->params[4];
	normal->k = plane->params[5];
}*/

/*
*	Plane equation: Ax + By + Cz + D = 0
*	With:
*		A, B, C = x, y, z components of the normal vector.
*		x, y, z = Coordinates of any point inside the plane.
*
*	D is unknown, so to find it we do:
*		Ax + By + Cz = -D
*	or:
*		D = ft_dot(normal, point);
*
*	Line equation: Px + tVx + Py + tVy + Pz + tVz = 0
*	With:
*		P(x, y, z)	= Origin point of ray.
*		t			= Scalar.
*		V(x, y, z)	= Ray direction.
*
*	Intersection: A(Px + tVx) + B(Py + tVy) + C(Pz + tVz) + D = 0
*	Or:
*		APx + AtVx + BPy + BtVy + CPz + CtVz + D = 0
*		APx + BPy + CPz + D = -AtVx - BtVy - CtVz
*		APx + BPy + CPz + D = t(-AVx-BVy-CVz)
*		(APx + BPy + CPz + D) / (-AVx - BVy - CVz) = t
*
*	If t > 0: At least one intersection, we return the first one.
*	As t is a scalar, the first one found (with the previous equation)
*	will give the closest point.
*	Else: Plane is outside of camera view or parallel without intersecting.
*/

/*int	ft_intersect_plane(t_data *data, t_ray *ray, t_object *plane)
{
	t_vector	point;
	t_vector	normal;
	int			t;

	if (!data)
		return (0);
	ft_init_vectors(plane, &point, &normal);
	t = (normal.i * point.i + normal.j * point.j + normal.k * point.k)
		/ (normal.i * ray->dir.i + normal.j * ray->dir.j
			+ normal.k * ray->dir.k);
	if (t <= 0 || t < data->t_min || t > data->t_max || t > ray->t)
		return (0);
	ray->collision = plane;
	ray->t = t;
	return (1);
}*/

/*t_vector	ft_pl_normal(t_object *pl)
{
	t_vector	normal;

	ft_vector_init(&normal, pl->params[3], pl->params[4], pl->params[5]);
	normal = ft_vector_normalize(&normal);
	return (normal);
}*/

t_vector	ft_pl_normal(t_object *pl, t_vector *dir)
{
	t_vector	normal;

	ft_vector_init(&normal, pl->params[3], pl->params[4], pl->params[5]);
	normal = ft_vector_normalize(&normal);
	if (ft_dot(dir, &normal) > 0)
		return (ft_vector_scalar(&normal, -1));
	else
		return (normal);
}

double	ft_plane_distance(t_data *data, t_object *pl, t_vector *dir
, t_vector *origin)
{
	t_vector	normal;
	t_vector	co;
	double		t;

	(void) data;
	ft_vector_init(&co, origin->i - pl->params[0],
		origin->j - pl->params[1], origin->k - pl->params[2]);
	ft_vector_init(&normal, pl->params[3], pl->params[4], pl->params[5]);
	normal = ft_vector_normalize(&normal);
	co = ft_vector_scalar(&co, -1);
	if (ft_dot(dir, &normal) == 0)
		return (DBL_MAX);
	t = ft_dot(&co, &normal) / ft_dot(dir, &normal);
	return (t);
}

t_vector	ft_intersect_plane(t_data *data, t_vector *dir, t_object *pl,
t_vector *origin)
{
	t_vector	hit_point;
	double		value;

	value = ft_plane_distance(data, pl, dir, origin);
	ft_vector_init(&hit_point, origin->i + dir->i * value,
		origin->j + dir->j * value, origin->k + dir->k * value);
	return (ft_apply_light(data, pl, &hit_point, ft_pl_normal(pl, dir)));
}
