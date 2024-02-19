/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:12:45 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/25 18:55:41 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vector
{
	double	i;
	double	j;
	double	k;
}	t_vector;

t_vector	*ft_vector_new(double i, double j, double k);
void		ft_vector_init(t_vector *v, double i, double j, double k);
double		ft_dot(t_vector *a, t_vector *b);
double		ft_vector_length(t_vector *vector);
t_vector	ft_vector_normalize(t_vector *vector);
t_vector	ft_vector_cross(t_vector *a, t_vector *b);
t_vector	ft_vector_scalar(t_vector *v, double s);
#endif
