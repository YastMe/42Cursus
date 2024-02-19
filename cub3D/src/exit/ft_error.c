/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:05:15 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/21 10:10:47 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_error(t_data *data, int err_code, char *err_msg)
{
	printf(RED);
	if (err_code == ERR_CUSTOM)
		printf("%s\n", err_msg);
	else if (err_code == ERR_SYSTEM)
		perror("System Error");
	else if (err_code == ERR_LIBMLX)
		printf("MLX Error: %s", mlx_strerror(mlx_errno));
	printf(DEFAULT);
	ft_exit(data, EXIT_FAILURE);
}
