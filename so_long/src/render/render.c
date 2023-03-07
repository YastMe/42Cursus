/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:34:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 15:37:52 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture)
{
	mlx_image_t		*image;

	image = mlx_texture_to_image(data->mlx, texture);
	if (!image)
	{
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, image,
			j * 32, i * 32) < 0)
		return (EXIT_FAILURE);
	if (texture == data->textures->coffee)
		return (ft_collectible_list(data, image));
	return (0);
}

int	ft_render_player(t_data *data)
{
	ft_start_pos(data);
	if (!data->textures->player)
		return (EXIT_FAILURE);
	data->character = mlx_texture_to_image(data->mlx, data->textures->player);
	if (!data->character)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->character, data->x * 32,
			data->y * 32) < 0)
		return (EXIT_FAILURE);
	return (0);
}

int	ft_render(t_data *data)
{
	t_textures	textures;

	data->textures = &textures;
	textures.coffee = mlx_load_png("textures/coffee.png");
	textures.exit = mlx_load_png("textures/stairs.png");
	textures.player = mlx_load_png("textures/Char/Stand/spr_Stand_Down.png");
	textures.ground = mlx_load_png("textures/Tiles/tile085.png");
	textures.water = mlx_load_png("textures/Tiles/tile093.png");
	ft_fill_map(data);
	ft_render_player(data);
	mlx_delete_texture(textures.coffee);
	mlx_delete_texture(textures.player);
	mlx_delete_texture(textures.ground);
	mlx_delete_texture(textures.water);
	mlx_delete_texture(textures.exit);
	return (0);
}
