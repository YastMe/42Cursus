/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anims.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:49:41 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/16 14:30:57 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	load_frisk(t_data *data, int i)
{
	char			*str;
	mlx_texture_t	*texture;
	char			*path;

	path = ft_itoa(i);
	str = ft_strjoin(path, ".png");
	free(path);
	path = ft_strjoin("textures/anim/frisk/", str);
	free(str);
	texture = mlx_load_png(path);
	data->anim.frisk[i] = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, data->anim.frisk[i],
		data->width - 100, data->height - 90);
	data->anim.frisk[i]->enabled = 0;
	mlx_delete_texture(texture);
	free(path);
}

static void	load_kururin(t_data *data, int i)
{
	char			*str;
	mlx_texture_t	*texture;
	char			*path;

	path = ft_itoa(i);
	str = ft_strjoin(path, ".png");
	free(path);
	path = ft_strjoin("textures/anim/kururin/", str);
	free(str);
	texture = mlx_load_png(path);
	data->anim.kururin[i] = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, data->anim.kururin[i],
		data->width - 100, data->height - 100);
	data->anim.kururin[i]->enabled = 0;
	mlx_delete_texture(texture);
	free(path);
}

static void	load_yastoru(t_data *data, int i)
{
	char			*str;
	mlx_texture_t	*texture;
	char			*path;

	path = ft_itoa(i);
	str = ft_strjoin(path, ".png");
	free(path);
	path = ft_strjoin("textures/anim/yastoru/", str);
	free(str);
	texture = mlx_load_png(path);
	data->anim.yastoru[i] = mlx_texture_to_image(data->mlx, texture);
	mlx_image_to_window(data->mlx, data->anim.yastoru[i],
		data->width - 100, data->height - 90);
	data->anim.yastoru[i]->enabled = 0;
	mlx_delete_texture(texture);
	free(path);
}

void	ft_load_anims(t_data *data)
{
	int				i;

	data->anim.frisk = malloc(sizeof(mlx_image_t) * 4);
	if (!data->anim.frisk)
		ft_error(data, ERR_SYSTEM, NULL);
	data->anim.kururin = malloc(sizeof(mlx_image_t) * 4);
	if (!data->anim.kururin)
		ft_error(data, ERR_SYSTEM, NULL);
	data->anim.yastoru = malloc(sizeof(mlx_image_t) * 4);
	if (!data->anim.yastoru)
		ft_error(data, ERR_SYSTEM, NULL);
	i = 0;
	while (i < 4)
	{
		load_frisk(data, i);
		load_kururin(data, i);
		load_yastoru(data, i);
		i++;
	}
}
