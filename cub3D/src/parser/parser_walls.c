/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:35:02 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/20 20:49:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	check_surroundings(t_data *data, char **map, int i, int j)
{
	if (i == 0 || j == 0 || !map[i + 1][j + 1]
		|| !map[i][j + 1] || !map[i + 1][j])
		ft_error(data, ERR_CUSTOM, "Open map.");
	if ((map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N'
		&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E' && map[i + 1][j] != 'W')
		|| (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != 'N'
		&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E' && map[i - 1][j] != 'W')
		|| (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != 'N'
		&& map[i][j + 1] != 'S' && map[i][j + 1] != 'E' && map[i][j + 1] != 'W')
		|| (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N'
		&& map[i][j - 1] != 'S' && map[i][j - 1] != 'E'
		&& map[i][j - 1] != 'W'))
		ft_error(data, ERR_CUSTOM, "Open map.");
}

void	ft_check_walls(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				check_surroundings(data, map, i, j);
			j++;
		}
		i++;
	}
}
