/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:45:33 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/16 14:39:54 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_rgb_init(t_rgb *rgb, unsigned char r,
unsigned char g, unsigned char b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}
