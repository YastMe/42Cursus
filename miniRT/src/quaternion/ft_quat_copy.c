/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:23:32 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/05 09:26:51 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/quaternion.h"

t_quaternion	*ft_quat_copy(t_quaternion *q)
{
	t_quaternion	*ret;

	ret = malloc(sizeof(t_quaternion));
	if (!ret)
		return (NULL);
	ret->x = q->x;
	ret->y = q->y;
	ret->z = q->z;
	ret->w = q->w;
	return (ret);
}
