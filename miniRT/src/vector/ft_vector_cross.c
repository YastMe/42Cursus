/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_cross.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:31:06 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/05 09:41:55 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

/*
x = i ; y = j ; z = k

ci = aj * bk − ak * bj
cj = ak * bi − ai * bk
ck = ai * bj − aj * bi
*/

t_vector	ft_vector_cross(t_vector *a, t_vector *b)
{
	return ((t_vector){a->j * b->k - a->k * b->j,
		a->k * b->i - a->i * b->k,
		a->i * b->j - a->j * b->i});
}
