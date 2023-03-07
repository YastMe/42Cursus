/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:44 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 15:35:38 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_fill_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				ft_render_sprite(i, j, data, data->textures->water);
			else
				ft_render_sprite(i, j, data, data->textures->ground);
			if (data->map[i][j] == 'C')
				ft_render_sprite(i, j, data, data->textures->coffee);
			if (data->map[i][j] == 'E')
				ft_render_sprite(i, j, data, data->textures->exit);
			j++;
		}
		i++;
	}
	return (0);
}
