/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:39 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/21 11:17:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_close(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit((t_data *) param, 0);
}

static void	ft_cleanup(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->n_wall)
		mlx_delete_texture(data->n_wall);
	if (data->s_wall)
		mlx_delete_texture(data->s_wall);
	if (data->e_wall)
		mlx_delete_texture(data->e_wall);
	if (data->w_wall)
		mlx_delete_texture(data->w_wall);
	if (data->paths.n_wall)
		free(data->paths.n_wall);
	if (data->paths.s_wall)
		free(data->paths.s_wall);
	if (data->paths.w_wall)
		free(data->paths.w_wall);
	if (data->paths.e_wall)
		free(data->paths.e_wall);
}

void	ft_clean_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit(t_data *data, int exit_code)
{
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	ft_cleanup(data);
	exit(exit_code);
}
