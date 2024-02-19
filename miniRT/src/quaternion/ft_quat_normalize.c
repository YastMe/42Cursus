/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:20:08 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/06 11:06:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/quaternion.h"

t_quaternion	ft_quat_normalize(t_quaternion *q)
{
	t_quaternion	ret;
	double			len;

	len = ft_quat_length(q);
	ret.x = q->x / len;
	ret.y = q->y / len;
	ret.z = q->z / len;
	ret.w = q->w / len;
	return (ret);
}
