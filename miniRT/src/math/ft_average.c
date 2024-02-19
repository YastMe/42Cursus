/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_average.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:43:59 by abeltran          #+#    #+#             */
/*   Updated: 2023/09/19 10:45:38 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	ft_average(int *array, int size)
{
	int		i;
	double	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		total += array[i];
		i++;
	}
	return (total / size);
}
