/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:00:19 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/02 12:23:24 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_valid_name(t_data *data, char *file)
{
	char	*aux;

	aux = file;
	while (*aux)
		aux++;
	while (file < aux)
	{
		if (*aux == '.')
			if (*aux + 1 && *aux + 2)
				if (aux[1] == 'r' && aux[2] == 't')
					return ;
		aux--;
	}
	ft_error(data, ERR_CUSTOM, "Provided file must have .rt extension");
}

static void	ft_number_conditions(t_data *data, int *lights,
	int *cameras, int *ambients)
{
	t_object	*aux;

	aux = data->scene;
	while (aux)
	{
		if (aux->type == light)
			*lights += 1;
		else if (aux->type == camera)
			*cameras += 1;
		else if (aux->type == ambient)
			ambients += 1;
		aux = aux->next;
	}
}

static void	ft_parameter_conditions(t_data *data)
{
	t_object	*aux;

	aux = data->scene;
	while (aux)
	{
		if (aux->type == camera && aux->param_nbr != 7)
			ft_error(data, ERR_CUSTOM, "Wrong camera definition.");
		else if (aux->type == ambient && aux->param_nbr != 4)
			ft_error(data, ERR_CUSTOM, "Wrong ambient light definition.");
		else if (aux->type == sphere && aux->param_nbr != 7)
			ft_error(data, ERR_CUSTOM, "Wrong sphere definition.");
		else if (aux->type == plane && (aux->param_nbr != 9
				|| ((aux->params[3] > 1 || aux->params[3] < -1)
					|| (aux->params[4] > 1 || aux->params[4] < -1)
					|| (aux->params[5] > 1 || aux->params[5] < -1))))
			ft_error(data, ERR_CUSTOM, "Wrong plane definition.");
		else if (aux->type == cylinder && (aux->param_nbr != 11
				|| ((aux->params[3] > 1 || aux->params[3] < -1)
					|| (aux->params[4] > 1 || aux->params[4] < -1)
					|| (aux->params[5] > 1 || aux->params[5] < -1))))
			ft_error(data, ERR_CUSTOM, "Wrong cylinder definition.");
		aux = aux->next;
	}
}

void	ft_parser_conditions(t_data *data)
{
	int	lights;
	int	cameras;
	int	ambients;

	lights = 0;
	cameras = 0;
	ambients = 0;
	ft_number_conditions(data, &lights, &cameras, &ambients);
	if (lights > 1)
		ft_error(data, ERR_CUSTOM, "There can be only one light in scene.");
	else if (cameras > 1)
		ft_error(data, ERR_CUSTOM, "There can be only one camera in scene.");
	else if (ambients > 1)
		ft_error(data, ERR_CUSTOM, "There can be only one source of\
			ambient light in scene.");
	ft_parameter_conditions(data);
	if (!data->bgcolor)
	{
		data->bgcolor = malloc(sizeof(t_rgb));
		if (!data->bgcolor)
			ft_error(data, ERR_SYSTEM, NULL);
		ft_vector_init(data->bgcolor, 0, 0, 0);
	}
}
