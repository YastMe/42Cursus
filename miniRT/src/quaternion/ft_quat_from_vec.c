/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_from_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:27:58 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/18 12:30:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/quaternion.h"

t_quaternion	ft_quat_from_vec(t_vector *first, t_vector *second)
{
	t_quaternion	quat;
	t_vector		axis;
	double			qw;
	double			d;

	d = ft_dot(first, second);
	ft_vector_init(&axis, first->i, first->j, first->k);
	axis = ft_vector_cross(&axis, second);
	qw = sqrt(ft_vector_length(first) * ft_vector_length(first)
			* ft_vector_length(second) * ft_vector_length(second)) + d;
	if (qw < 0.001)
	{
		quat = ft_quat_init(0, 1, 0, 0);
		return (ft_quat_normalize(&quat));
	}
	quat = ft_quat_init(axis.i, axis.j, axis.k, qw);
	return (ft_quat_normalize(&quat));
}
