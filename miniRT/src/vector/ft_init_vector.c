/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:03:34 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/05 00:05:57 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

void	ft_vector_init(t_vector *v, double i, double j, double k)
{
	v->i = i;
	v->j = j;
	v->k = k;
}
