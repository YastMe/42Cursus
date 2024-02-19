/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:28:28 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/05 00:05:59 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vector.h"

t_vector	*ft_vector_new(double i, double j, double k)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	new->i = i;
	new->j = j;
	new->k = k;
	return (new);
}
