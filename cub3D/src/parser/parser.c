/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:03:50 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/21 17:38:12 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	count_lines(t_data *data, char *filename)
{
	char	*buff;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_SYSTEM, NULL);
	buff = get_next_line(fd);
	while (buff[0] == 'N' || buff[0] == 'S' || buff[0] == 'W'
		|| buff[0] == 'E' || buff[0] == 'F' || buff[0] == 'C'
		|| buff[0] == '\n')
	{
		free(buff);
		buff = get_next_line(fd);
	}
	while (buff && buff[0] != '\n')
	{
		count++;
		free(buff);
		buff = get_next_line(fd);
	}
	if (buff)
		free(buff);
	return (count);
}

static void	set_colors(t_data *d, char **split)
{
	uint8_t		color[3];
	char		**colors_str;
	int			i;

	colors_str = ft_split(split[1], ',');
	if (!colors_str)
		ft_error(d, ERR_SYSTEM, NULL);
	i = 0;
	while (colors_str[i])
		i++;
	if (i < 3 && split[0][0] != '\n')
	{
		ft_clean_array(split);
		ft_clean_array(colors_str);
		ft_error(d, ERR_CUSTOM, "No color or invalid color provided.");
	}
	i = -1;
	while (++i < 3)
		color[i] = ft_atoi(colors_str[i]);
	if (split[0][0] == 'F')
		d->floor = color[0] << 24 | color[1] << 16 | color[2] << 8 | 0x000000FF;
	else
		d->sky = color[0] << 24 | color[1] << 16 | color[2] << 8 | 0x000000FF;
	ft_clean_array(colors_str);
}

static void	save_paths(t_data *data, char *buff)
{
	char	**split;
	int		len;

	split = ft_split(buff, ' ');
	if (!split)
	{
		ft_clean_array(split);
		ft_error(data, ERR_SYSTEM, NULL);
	}
	len = 0;
	while (split[len])
		len++;
	if (len <= 1 && split[0][0] != '\n')
		ft_error(data, ERR_CUSTOM, "No texture provided.");
	if (ft_strncmp(buff, "NO", 2) == 0)
		data->paths.n_wall = ft_strdup(split[1]);
	else if (ft_strncmp(buff, "SO", 2) == 0)
		data->paths.s_wall = ft_strdup(split[1]);
	else if (ft_strncmp(buff, "WE", 2) == 0)
		data->paths.w_wall = ft_strdup(split[1]);
	else if (ft_strncmp(buff, "EA", 2) == 0)
		data->paths.e_wall = ft_strdup(split[1]);
	else if (split[0][0] == 'F' || split[0][0] == 'C')
		set_colors(data, split);
	ft_clean_array(split);
}

static char	*parse_textures(int fd, t_data *data)
{
	char	*buff;

	buff = ft_skip_lines(fd);
	while (ft_strncmp(buff, "NO", 2) == 0 || ft_strncmp(buff, "SO", 2) == 0
		|| ft_strncmp(buff, "WE", 2) == 0 || ft_strncmp(buff, "EA", 2) == 0
		|| ft_strncmp(buff, "\n", 1) == 0 || buff[0] == 'F' || buff[0] == 'C')
	{
		if (ft_strncmp(buff, "NO", 2) == 0 && data->paths.n_wall)
			ft_error(data, ERR_CUSTOM, "Duplicated north wall texture.");
		if (ft_strncmp(buff, "SO", 2) == 0 && data->paths.s_wall)
			ft_error(data, ERR_CUSTOM, "Duplicated south wall texture.");
		if (ft_strncmp(buff, "EA", 2) == 0 && data->paths.e_wall)
			ft_error(data, ERR_CUSTOM, "Duplicated east wall texture.");
		if (ft_strncmp(buff, "WE", 2) == 0 && data->paths.w_wall)
			ft_error(data, ERR_CUSTOM, "Duplicated west wall texture.");
		if (ft_strncmp(buff, "C", 1) == 0 && data->sky != 0)
			ft_error(data, ERR_CUSTOM, "Duplicated sky color.");
		if (ft_strncmp(buff, "F", 1) == 0 && data->floor != 0)
			ft_error(data, ERR_CUSTOM, "Duplicated floor color.");
		save_paths(data, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	return (buff);
}

void	ft_parse(t_data *data, char *filename)
{
	char	**map;
	int		fd;
	int		i;
	int		*coords;

	i = count_lines(data, filename) + 1;
	map = (char **) malloc(sizeof(char *) * i);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(data, ERR_SYSTEM, NULL);
	i = 0;
	map[i] = parse_textures(fd, data);
	while (map[i] && map[i][0] != '\n')
	{
		i++;
		map[i] = get_next_line(fd);
	}
	if (map[i] && map[i][0] == '\n')
		free(map[i]);
	map[i] = 0;
	data->map = map;
	coords = ft_player_coords(map);
	ft_set_position(data, coords);
}
