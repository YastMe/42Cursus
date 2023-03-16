/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:34:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:56:07 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
	if (texture == data->textures->trap_0)
		return (ft_trap_list(data, image));
	return (0);
}

void	ft_load_textures(t_textures *textures)
{
	textures->coffee = mlx_load_png("textures/coffee.png");
	textures->exit_empty = mlx_load_png("textures/Pot/pot_1.png");
	textures->exit_1 = mlx_load_png("textures/Pot/pot_2.png");
	textures->exit_2 = mlx_load_png("textures/Pot/pot_3.png");
	textures->exit_3 = mlx_load_png("textures/Pot/pot_4.png");
	textures->exit_4 = mlx_load_png("textures/Pot/pot_5.png");
	textures->player = mlx_load_png("textures/Char/Down.png");
	textures->ground = mlx_load_png("textures/Tiles/tile085.png");
	textures->water = mlx_load_png("textures/Tiles/tile093.png");
	textures->trap_0 = mlx_load_png("textures/Trap/trap_00.png");
	textures->trap_1 = mlx_load_png("textures/Trap/trap_01.png");
}

void	ft_free_textures(t_textures *textures)
{
	mlx_delete_texture(textures->coffee);
	mlx_delete_texture(textures->player);
	mlx_delete_texture(textures->ground);
	mlx_delete_texture(textures->water);
	mlx_delete_texture(textures->exit_empty);
	mlx_delete_texture(textures->exit_1);
	mlx_delete_texture(textures->exit_2);
	mlx_delete_texture(textures->exit_3);
	mlx_delete_texture(textures->exit_4);
	mlx_delete_texture(textures->trap_0);
	mlx_delete_texture(textures->trap_1);
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
	data->character->enabled = 0;
	return (0);
}

int	ft_render(t_data *data)
{
	t_textures	textures;

	ft_load_textures(&textures);
	data->textures = &textures;
	ft_fill_map(data);
	ft_render_player(data);
	ft_free_textures(&textures);
	ft_load_anims(data);
	ft_render_moves(data);
	return (0);
}
