/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:38:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/16 14:31:18 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	anim_frisk(t_data *data)
{
	if (data->anim.frame == 0)
		data->anim.frisk[3]->enabled = 0;
	else
		data->anim.frisk[data->anim.frame - 1]->enabled = 0;
	data->anim.frisk[data->anim.frame]->enabled = 1;
}

static void	anim_kururin(t_data *data)
{
	if (data->anim.frame == 0)
		data->anim.kururin[3]->enabled = 0;
	else
		data->anim.kururin[data->anim.frame - 1]->enabled = 0;
	data->anim.kururin[data->anim.frame]->enabled = 1;
}

static void	anim_yastoru(t_data *data)
{
	if (data->anim.frame == 0)
		data->anim.yastoru[3]->enabled = 0;
	else
		data->anim.yastoru[data->anim.frame - 1]->enabled = 0;
	data->anim.yastoru[data->anim.frame]->enabled = 1;
}

void	ft_disable_anims(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->anim.frisk[i]->enabled = 0;
		data->anim.kururin[i]->enabled = 0;
		data->anim.yastoru[i]->enabled = 0;
		i++;
	}
}

void	ft_anim_spin(t_data *data)
{
	if (data->timer_anim < 0.05)
	{
		data->timer_anim += data->mlx->delta_time;
		return ;
	}
	else
		data->timer_anim = 0;
	data->anim.frame += 1;
	if (data->anim.frame == 4)
		data->anim.frame = 0;
	if (data->anim.selected == 0)
		anim_frisk(data);
	else if (data->anim.selected == 1)
		anim_kururin(data);
	else
		anim_yastoru(data);
}
