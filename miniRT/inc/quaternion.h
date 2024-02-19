/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:15:49 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/06 10:15:48 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "vector.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_quaternion
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_quaternion;

t_quaternion	ft_quat_init(double x, double y, double z, double w);
t_quaternion	*ft_quat_copy(t_quaternion *q);
t_quaternion	ft_quat_from_vec(t_vector *first, t_vector *second);
t_quaternion	ft_quat_conjugate(t_quaternion *q);
t_quaternion	ft_quat_mul(t_quaternion *a, t_quaternion *b);
t_quaternion	ft_quat_normalize(t_quaternion *q);
double			ft_quat_length(t_quaternion *q);
t_vector		ft_vector_rotate(t_vector *v, t_quaternion *q);

#endif
