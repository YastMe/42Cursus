/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:01:08 by abeltran          #+#    #+#             */
/*   Updated: 2023/09/21 10:06:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	ft_normalize(double n, double min, double max)
{
	double	res;

	res = (n - min) / (max - min);
	return (res);
}

double	ft_denormalize(double n, double min, double max)
{
	double	res;

	res = n * (max - min) + min;
	return (res);
}
