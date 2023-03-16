/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:21:00 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/15 15:43:54 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_get_exit(t_data *data)
{
	float		p;
	int			i;

	if (data->collectibles == 0)
	{
		data->exit_images[3]->enabled = 0;
		data->exit_images[4]->enabled = 1;
	}
	else if (data->collectibles == data->total_collectibles)
		data->exit_images[0]->enabled = 1;
	else
	{
		p = (float) data->collectibles / (float) data->total_collectibles * 100;
		if (p >= 1 && p <= 33)
			i = 3;
		else if (p >= 34 && p <= 66)
			i = 2;
		else
			i = 1;
		data->exit_images[i]->enabled = 1;
		data->exit_images[--i]->enabled = 0;
	}
}

void	ft_check_collectibles(t_data *data)
{
	int			i;
	mlx_image_t	*img;

	if (data->map[data->y][data->x] == 'C')
	{
		i = 0;
		while (data->collectible_images[i])
		{
			img = data->collectible_images[i];
			if (img->instances[0].x
				== data->character->instances[0].x
				&& img->instances[0].y
				== data->character->instances[0].y)
			{
				data->collectible_images[i]->enabled = 0;
				data->collectibles--;
				data->map[data->y][data->x] = '0';
				ft_get_exit(data);
				return ;
			}
			i++;
		}
	}
}

int	ft_collectible_list(t_data *data, mlx_image_t *image)
{
	if (data->collectibles == 0)
	{
		data->collectible_images = malloc(sizeof(mlx_image_t *)
				* (data->total_collectibles + 1));
		if (!data->collectible_images)
			return (EXIT_FAILURE);
		data->collectible_images[0] = image;
		data->collectibles = 1;
		data->collectible_images[data->total_collectibles] = 0;
	}
	else
	{
		data->collectible_images[data->collectibles] = image;
		data->collectibles++;
	}
	return (0);
}
