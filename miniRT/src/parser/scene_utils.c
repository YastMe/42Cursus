/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:16:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/10/12 19:50:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_object	*selective_add(t_object *obj, t_object *list)
{
	t_object	*aux;

	if (!list)
		list = obj;
	else
	{
		aux = list;
		while (aux->next)
			aux = aux->next;
		aux->next = obj;
	}
	return (list);
}

void	ft_add_to_scene(t_data *data, t_object *obj)
{
	if (obj->type == camera)
	{
		ft_init_camera(data, obj);
		return ;
	}
	ft_set_colors(data, obj);
	if (obj->type == background)
		data->bgcolor = obj->color;
	if (obj->type == light && obj->params[3] > 0)
		data->lights = selective_add(obj, data->lights);
	else if (obj->type == ambient)
	{
		data->ambient = obj;
	}
	else if (obj->type == light)
		ft_clean_scene(obj);
	else
		data->scene = selective_add(obj, data->scene);
}
