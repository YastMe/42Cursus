/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:37:22 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/03 10:24:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	subparams(char *subparam)
{
	char	**split;
	int		i;

	split = ft_split(subparam, ',');
	i = 0;
	while (split[i])
		i++;
	ft_clean_array(split);
	return (i);
}

int	ft_count_params(char **pre_parse)
{
	int	i;
	int	param_nbr;

	i = 1;
	param_nbr = 0;
	while (pre_parse[i])
	{
		param_nbr += subparams(pre_parse[i]);
		i++;
	}
	return (param_nbr);
}

void	ft_init_params(int param_nbr, double *params)
{
	int	i;

	i = 0;
	while (i < param_nbr)
	{
		params[i] = 0;
		i++;
	}
}

void	ft_fix_coords(t_object *obj)
{
	if (obj->type != ambient && obj->type != background)
		obj->params[1] = obj->params[1] * -1;
}

void	ft_set_colors(t_data *data, t_object	*obj)
{
	t_vector	*color;

	color = NULL;
	obj->color = color;
	if (obj->type == camera)
		return ;
	color = malloc(sizeof(t_vector));
	if (!color)
		ft_error(data, ERR_SYSTEM, NULL);
	ft_vector_init(color, obj->params[obj->param_nbr - 3] / 255,
		obj->params[obj->param_nbr - 2] / 255,
		obj->params[obj->param_nbr - 1] / 255);
	obj->color = color;
}
