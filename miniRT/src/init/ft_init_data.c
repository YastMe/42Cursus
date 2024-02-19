/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:12:50 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/25 11:30:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!data->mlx)
		ft_error(data, ERR_LIBMLX, NULL);
	data->canvas = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->canvas)
		ft_error(data, ERR_LIBMLX, NULL);
	if (mlx_image_to_window(data->mlx, data->canvas, 0, 0) == -1)
		ft_error(data, ERR_LIBMLX, NULL);
}

void	ft_init_camera(t_data *data, t_object *camera)
{
	data->cam.position.i = camera->params[0];
	data->cam.position.j = camera->params[1];
	data->cam.position.k = camera->params[2];
	data->cam.rotation.i = camera->params[3];
	data->cam.rotation.j = camera->params[4];
	data->cam.rotation.k = camera->params[5];
	ft_vector_init(&data->forward, 0, 0, 5);
	data->cam.fov = camera->params[camera->param_nbr - 1];
	data->rotation = ft_quat_init(0, 0, 0, 1);
	data->cam.initialized = 1;
	free(camera->params);
	free(camera);
}

void	ft_init_data(t_data *data)
{
	init_mlx_data(data);
	data->scene = NULL;
	data->lights = NULL;
	data->bgcolor = NULL;
	data->cam.initialized = 0;
}
