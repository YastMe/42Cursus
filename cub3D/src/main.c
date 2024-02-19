/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:38:45 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/21 11:25:58 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_void(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_data		data;

	(void) argc;
	data.mlx = NULL;
	if (argc != 2)
		ft_error(&data, ERR_CUSTOM, "Usage: ./cub3D <filename.cub>");
	ft_init(&data, argv[1]);
	mlx_loop_hook(data.mlx, ft_main_loop, &data);
	mlx_key_hook(data.mlx, ft_close, &data);
	ft_render(&data);
	mlx_loop(data.mlx);
	ft_exit(&data, EXIT_SUCCESS);
}
