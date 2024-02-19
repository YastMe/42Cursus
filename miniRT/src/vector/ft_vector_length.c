/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:27:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/06 10:28:05 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

double	ft_vector_length(t_vector *vector)
{
	return (sqrt(vector->i * vector->i + vector->j * vector->j
			+ vector->k * vector->k));
}
