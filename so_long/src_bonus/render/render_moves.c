/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:42:20 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:45:58 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_render_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->moves);
	mlx_delete_image(data->mlx, data->text);
	data->text = mlx_put_string(data->mlx, moves, 8, 4);
	free(moves);
}
