/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:41:21 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:54:19 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_load_anim_textures(mlx_texture_t **textures)
{
	textures[0] = mlx_load_png("textures/Char/Up.png");
	textures[1] = mlx_load_png("textures/Char/Down.png");
	textures[2] = mlx_load_png("textures/Char/Left.png");
	textures[3] = mlx_load_png("textures/Char/Right.png");
}

void	ft_load_anim_images(mlx_image_t **images, mlx_texture_t **textures,
	t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		images[i] = mlx_texture_to_image(data->mlx, textures[i]);
		if (!images[i])
		{
			data->loaded_anims = 0;
			return ;
		}
		i++;
	}
	data->loaded_anims = 1;
}

void	ft_render_anims(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->anim_image_frames[i])
		{
			if (mlx_image_to_window(data->mlx, data->anim_image_frames[i],
					data->x * 32, data->y * 32) < 0)
			{
				data->loaded_anims = 0;
				return ;
			}
		}
		else
		{
			data->loaded_anims = 0;
			return ;
		}
		data->anim_image_frames[i]->enabled = 0;
		i++;
	}
	data->loaded_anims = 1;
}

void	ft_clear_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(data->anim_texture_frames[i]);
		i++;
	}
}

void	ft_load_anims(t_data *data)
{
	data->anim_texture_frames = malloc(sizeof(mlx_texture_t *) * 4);
	if (!data->anim_texture_frames)
	{
		data->loaded_anims = 0;
		return ;
	}
	data->anim_image_frames = malloc(sizeof(mlx_image_t *) * 4);
	if (!data->anim_image_frames)
	{
		data->loaded_anims = 0;
		return ;
	}
	ft_load_anim_textures(data->anim_texture_frames);
	ft_load_anim_images(data->anim_image_frames,
		data->anim_texture_frames, data);
	if (data->loaded_anims)
		ft_render_anims(data);
	if (data->loaded_anims)
		data->anim_image_frames[1]->enabled = 1;
	ft_clear_textures(data);
}
