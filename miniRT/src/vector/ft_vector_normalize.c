/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:25:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/27 23:32:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

t_vector	ft_vector_normalize(t_vector *vector)
{
	double	len;

	len = ft_vector_length(vector);
	return ((t_vector){vector->i / len, vector->j / len, vector->k / len});
}
