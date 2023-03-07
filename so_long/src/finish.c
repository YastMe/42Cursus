/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:43 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 14:24:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_program(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

void	ft_check_end(t_data *data)
{
	if (!data->collectibles)
	{
		mlx_close_window(data->mlx);
		ft_printf("OLE AHÍ ER BETIIII\n");
	}
	else
		ft_printf("Farta beti.\n");
}

void	ft_finish(t_data *data)
{
	mlx_terminate(data->mlx);
}
