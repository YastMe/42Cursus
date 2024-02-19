/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:55:09 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/05 10:05:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/quaternion.h"

t_quaternion	ft_quat_mul(t_quaternion *a, t_quaternion *b)
{
	t_quaternion	ret;

	ret.x = (a->w * b->x) + (a->x * b->w) + (a->y * b->z) - (a->z * b->y);
	ret.y = (a->w * b->y) + (a->y * b->w) + (a->z * b->x) - (a->x * b->z);
	ret.z = (a->w * b->z) + (a->z * b->w) + (a->x * b->y) - (a->y * b->x);
	ret.w = (a->w * b->w) - (a->x * b->x) - (a->y * b->y) - (a->z * b->z);
	return (ret);
}
