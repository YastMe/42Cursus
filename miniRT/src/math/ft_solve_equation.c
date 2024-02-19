/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_equation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:16:18 by abeltran          #+#    #+#             */
/*   Updated: 2023/09/28 00:49:57 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	*ft_solve_equation(double a, double b, double c)
{
	double	radical;
	double	*values;

	values = (double *)malloc(sizeof(double) * 2);
	if (!values)
		ft_error(NULL, ERR_SYSTEM, NULL);
	radical = b * b - 4.0f * a * c;
	if (radical < 0.0f)
		return (free(values), NULL);
	values[0] = (-b - sqrt(radical)) / (2.0f * a);
	values[1] = (-b + sqrt(radical)) / (2.0f * a);
	return (values);
}
