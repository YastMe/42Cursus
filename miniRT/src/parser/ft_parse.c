/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:11:26 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/02 12:40:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static double	*get_params(char **pre_parse, int param_nbr)
{
	double	*params;
	char	**subparam;
	int		i;
	int		j;
	int		k;

	params = malloc(sizeof(double) * param_nbr);
	ft_init_params(param_nbr, params);
	i = 1;
	k = 0;
	while (pre_parse[i])
	{
		subparam = ft_split(pre_parse[i], ',');
		j = 0;
		while (subparam[j])
		{
			params[k] = ft_atod(subparam[j]);
			j++;
			k++;
		}
		ft_clean_array(subparam);
		i++;
	}
	return (params);
}

static enum e_obj	get_type(char *type_pre)
{
	enum e_obj	type;

	if (!ft_strncmp(type_pre, "L", 1))
		type = light;
	else if (!ft_strncmp(type_pre, "C", 1))
		type = camera;
	else if (!ft_strncmp(type_pre, "A", 1))
		type = ambient;
	else if (!ft_strncmp(type_pre, "sp", 2))
		type = sphere;
	else if (!ft_strncmp(type_pre, "pl", 2))
		type = plane;
	else if (!ft_strncmp(type_pre, "cy", 2))
		type = cylinder;
	else if (!ft_strncmp(type_pre, "bg", 2))
		type = background;
	else
		type = none;
	return (type);
}

static void	build_object(t_data *data, char *line)
{
	char		**pre_parse;
	t_object	*obj;

	if (ft_strlen(line) == 1)
		return ;
	pre_parse = ft_split(line, ' ');
	obj = malloc(sizeof(t_object));
	if (!obj)
		ft_error(data, ERR_SYSTEM, NULL);
	obj->type = get_type(*pre_parse);
	if (obj->type == none)
	{
		ft_clean_array(pre_parse);
		free(obj);
		return ;
	}
	if (obj->type != light)
		obj->param_nbr = ft_count_params(pre_parse);
	else
		obj->param_nbr = 7;
	obj->params = get_params(pre_parse, obj->param_nbr);
	obj->next = NULL;
	ft_add_to_scene(data, obj);
	ft_clean_array(pre_parse);
}

void	ft_parse(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	ft_valid_name(data, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(data, ERR_FILE, NULL);
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		build_object(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_parser_conditions(data);
}
