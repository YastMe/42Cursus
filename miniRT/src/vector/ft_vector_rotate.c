/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:08:30 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/06 12:05:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"
#include "../../inc/quaternion.h"

t_vector	ft_vector_rotate(t_vector *v, t_quaternion *q)
{
	t_quaternion	p;
	t_quaternion	q_conjugate;
	t_quaternion	aux;

	(void) q_conjugate;
	p = ft_quat_init(v->i, v->j, v->k, 0);
	q_conjugate = ft_quat_conjugate(q);
	aux = ft_quat_mul(q, &p);
	aux = ft_quat_mul(&aux, &q_conjugate);
	return ((t_vector){aux.x, aux.y, aux.z});
}
