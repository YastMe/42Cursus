/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:46 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/21 17:38:09 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	check_textures(t_data *data)
{
	int	fd;

	if (!data->paths.n_wall || !data->paths.s_wall
		|| !data->paths.e_wall || !data->paths.w_wall)
		ft_error(data, ERR_CUSTOM, "Textures must be at the start of the file");
	fd = open(data->paths.n_wall, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_CUSTOM, "Invalid filename (north wall).");
	close(fd);
	fd = open(data->paths.s_wall, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_CUSTOM, "Invalid filename (south wall).");
	close(fd);
	fd = open(data->paths.e_wall, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_CUSTOM, "Invalid filename (east wall).");
	close(fd);
	fd = open(data->paths.w_wall, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_CUSTOM, "Invalid filename (west wall).");
	close(fd);
	if (!data->sky)
		ft_error(data, ERR_CUSTOM, "Invalid sky color.");
	if (!data->floor)
		ft_error(data, ERR_CUSTOM, "Invalid floor color.");
}

static void	weird_chars(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
			&& map[i][j] != '\n' && map[i][j] != 'N' && map[i][j] != 'S'
			&& map[i][j] != 'E' && map[i][j] != 'W')
				ft_error(data, ERR_CUSTOM, "Invalid map character.");
			j++;
		}
		i++;
	}
}

static int	count_chars(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	check_map(t_data *data)
{
	int	count;

	count = 0;
	weird_chars(data, data->map);
	count += count_chars(data->map, 'N');
	count += count_chars(data->map, 'S');
	count += count_chars(data->map, 'W');
	count += count_chars(data->map, 'E');
	if (count >= 1)
		ft_error(data, ERR_CUSTOM, "Multiple starting positions detected.");
	if (data->player.pos.x == 0 && data->player.pos.y == 0)
		ft_error(data, ERR_CUSTOM, "No starting position detected.");
	ft_check_walls(data, data->map);
}

void	ft_parser_check(t_data *data)
{
	check_map(data);
	check_textures(data);
}
