/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:00:49 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/09 20:44:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_flood_fill(char **tab, t_point size, t_point begin, t_data *data)
{
	char	c;
	c = tab[begin.y][begin.x];
	if (c == 'E')
		data->exit = 1;
	else if (c == 'C')
		data->collectibles++;
	tab[begin.y][begin.x] = 'F';
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] != '1' && tab[begin.y][begin.x + 1] != 'F')
	{
		begin.x++;
		ft_flood_fill(tab, size, begin, data);
	}
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] != '1' && tab[begin.y][begin.x - 1] != 'F')
	{
		begin.x--;
		ft_flood_fill(tab, size, begin, data);
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] != '1' && tab[begin.y + 1][begin.x] != 'F')
	{
		begin.y++;
		ft_flood_fill(tab, size, begin, data);
	}
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] != '1' && tab[begin.y - 1][begin.x] != 'F')
	{
		begin.y--;
		ft_flood_fill(tab, size, begin, data);
	}
}

int	ft_validate(t_data *data)
{
	t_point		begin;
	t_point		size;

	ft_start_pos(data);
	begin.x = data->x;
	begin.y = data->y;
	size.x = data->size_x;
	size.y = data->size_y;
	ft_flood_fill(data->map, size, begin, data);
	if (data->exit && data->collectibles == data->total_collectibles)
		return (1);
	return (0);
}