/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:25:38 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 14:16:58 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_data(t_data *data)
{
	int	i;

	ft_printf("Data:\n  Pos: %d,%d\n  Size: %d*%d\n\n",
		data->x, data->y, data->size_x, data->size_y);
	i = 0;
	while (data->map[i])
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_init(t_data *data)
{
	data->character = NULL;
	data->collectibles = 0;
	data->total_collectibles = 0;
	data->end = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->moves = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->textures = NULL;
	data->x = 0;
	data->y = 0;
	data->key_pressed = 0;
}

int	ft_start(void)
{
	t_data	data;

	ft_init(&data);
	read_map_file("src/test", &data);
	ft_collectibles(&data);
	data.mlx = mlx_init(data.size_x * 32, data.size_y * 32, "so_long", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx, &ft_update, &data);
	ft_render(&data);
	ft_print_data(&data);
	mlx_loop(data.mlx);
	ft_finish(&data);
	return (EXIT_SUCCESS);
}
