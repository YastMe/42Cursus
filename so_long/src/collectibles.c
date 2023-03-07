/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:21:00 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 15:03:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_collectibles(t_data *data)
{
	int			i;
	mlx_image_t	*img;

	if (data->map[data->y][data->x] == 'C')
	{
		i = 0;
		while (data->images[i])
		{
			img = data->images[i];
			if (img->instances[0].x
				== data->character->instances[0].x
				&& img->instances[0].y
				== data->character->instances[0].y)
			{
				data->images[i]->enabled = 0;
				data->collectibles--;
				data->map[data->y][data->x] = '0';
				ft_printf("Betiiii\n");
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
		data->images = malloc(data->total_collectibles + 1);
		if (!data->images)
			return (EXIT_FAILURE);
		data->images[0] = image;
		data->collectibles = 1;
		data->images[data->total_collectibles] = 0;
	}
	else
	{
		data->images[data->collectibles] = image;
		data->collectibles++;
	}
	return (0);
}
