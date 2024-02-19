/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:41:46 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/20 22:11:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_base_minimap(t_data *data)
{
	int				i;
	int				j;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./textures/map/wall.png");
	img = mlx_texture_to_image(data->mlx, texture);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, img, j * 8, i * 8);
			j++;
		}
		i++;
	}
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/map/player.png");
	data->mapplayer = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, data->mapplayer, data->player.pos.x * 8,
		data->player.pos.y * 8);
	mlx_delete_texture(texture);
}
