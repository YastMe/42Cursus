/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:48 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/25 17:05:08 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	ft_update_movement(t_data *data, double *change, double value)
{
	*change += value;
	ft_render_scene(data);
}

void	ft_movement(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_update_movement(data, &data->cam.position.k, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_update_movement(data, &data->cam.position.i, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_update_movement(data, &data->cam.position.k, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_update_movement(data, &data->cam.position.i, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		ft_update_movement(data, &data->cam.position.j, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		ft_update_movement(data, &data->cam.position.j, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		ft_update_movement(data, &data->rotation.x, 0.005);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		ft_update_movement(data, &data->rotation.x, -0.005);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_update_movement(data, &data->rotation.y, -0.005);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_update_movement(data, &data->rotation.y, 0.005);
}
// S = sqrt(2^2 + 2^2)
//
// FOV = 2 * arctan(S / 2f)
// f = (S / tan(FOV / 2)) / 2
