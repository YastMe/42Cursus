/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_conjugate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:50:32 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/05 09:52:45 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/quaternion.h"

t_quaternion	ft_quat_conjugate(t_quaternion *q)
{
	return ((t_quaternion){-q->x, -q->y, -q->z, q->w});
}
