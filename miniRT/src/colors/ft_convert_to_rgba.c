/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_rgba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:11 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/02 11:56:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

uint32_t	ft_convert_to_rgba(t_vector *color)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	result;

	r = (uint8_t)(color->i * 255);
	g = (uint8_t)(color->j * 255);
	b = (uint8_t)(color->k * 255);
	result = (r << 24) | (g << 16) | (b << 8) | (uint8_t)255;
	return (result);
}
