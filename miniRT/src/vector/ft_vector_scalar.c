/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_scalar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:53:11 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/25 18:54:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

t_vector	ft_vector_scalar(t_vector *v, double s)
{
	return ((t_vector){v->i * s, v->j * s, v->k * s});
}
