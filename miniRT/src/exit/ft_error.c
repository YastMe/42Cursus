/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:47:43 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/06 12:18:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_error(t_data *data, int err_code, char *err_msg)
{
	printf(RED);
	if (err_code == ERR_CUSTOM)
		printf("%s\n", err_msg);
	else if (err_code == ERR_SYSTEM)
		perror("System Error");
	else if (err_code == ERR_LIBMLX)
		printf("MLX Error: %s", mlx_strerror(mlx_errno));
	else if (err_code == ERR_FILE)
		printf("%s\n", strerror(errno));
	printf(DEFAULT);
	ft_exit(data, EXIT_FAILURE);
}
