/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:56:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/16 14:29:46 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_rotate_right(t_player *p)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = p->dir.x;
	p->dir.x = p->dir.x * cosf(-p->rot_speed) - p->dir.y * sinf(-p->rot_speed);
	p->dir.y = old_dirx * sinf(-p->rot_speed) + p->dir.y * cosf(-p->rot_speed);
	old_planex = p->plane.x;
	p->plane.x = p->plane.x * cosf(-p->rot_speed) - p->plane.y
		* sinf(-p->rot_speed);
	p->plane.y = old_planex * sinf(-p->rot_speed) + p->plane.y
		* cosf(-p->rot_speed);
}

void	ft_rotate_left(t_player *p)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = p->dir.x;
	p->dir.x = p->dir.x * cosf(p->rot_speed) - p->dir.y * sinf(p->rot_speed);
	p->dir.y = old_dirx * sinf(p->rot_speed) + p->dir.y * cosf(p->rot_speed);
	old_planex = p->plane.x;
	p->plane.x = p->plane.x * cosf(p->rot_speed) - p->plane.y
		* sinf(p->rot_speed);
	p->plane.y = old_planex * sinf(p->rot_speed) + p->plane.y
		* cosf(p->rot_speed);
}
