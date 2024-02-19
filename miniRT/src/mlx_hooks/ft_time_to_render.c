/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_to_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:21:47 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/06 10:40:01 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_time_to_render(void *params)
{
	struct timeval	current_frame;
	char			*base;
	char			*time;
	char			*final;
	t_data			*data;

	data = (t_data *)params;
	mlx_delete_image(data->mlx, data->render_time);
	gettimeofday(&current_frame, NULL);
	base = "Render time: ";
	time = ft_itoa((current_frame.tv_sec * 1000 + current_frame.tv_usec / 1000)
			- (data->last_frame.tv_sec * 1000
				+ data->last_frame.tv_usec / 1000));
	final = ft_strjoin(base, time);
	base = "ms";
	free(time);
	time = ft_strjoin(final, base);
	data->render_time = mlx_put_string(data->mlx, time, 10, 10);
	free(time);
	free(final);
	data->last_frame = current_frame;
}
