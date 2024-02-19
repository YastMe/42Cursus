/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:59:06 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/25 12:39:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	ft_void(void)
{
	system("leaks -q miniRT");
}

static void	setup_rotation(t_data *data)
{
	data->rotation = ft_quat_from_vec(&data->forward, &data->cam.rotation);
	data->cam.rotation = ft_vector_normalize(&data->cam.rotation);
	data->forward.k = (sqrt(8) / tan((data->cam.fov / 2) * (M_PI / 180))) / 2;
}

static bool	validate_scene(t_data *data)
{
	if (!data->ambient || !data->cam.initialized)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data			data;

	(void)argc;
	if (argc != 2)
		return (printf("Usage: miniRT <filename.rt>\n"), 1);
	//atexit(ft_void);
	ft_init_data(&data);
	ft_parse(&data, argv[1]);
	if (!validate_scene(&data))
	{
		printf(RED"Invalid scene file\n"DEFAULT);
		return (1);
	}
	setup_rotation(&data);
	gettimeofday(&data.last_frame, NULL);
	ft_render_scene(&data);
	ft_time_to_render(&data);
	mlx_loop_hook(data.mlx, &ft_movement, &data);
	mlx_loop_hook(data.mlx, &ft_time_to_render, &data);
	mlx_key_hook(data.mlx, &ft_close_window, &data);
	mlx_loop(data.mlx);
	ft_exit(&data, EXIT_SUCCESS);
	return (0);
}
