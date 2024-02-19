/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:50:51 by abeltran          #+#    #+#             */
/*   Updated: 2023/09/22 13:51:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_clean_array(char	**array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	ft_clean_scene(t_object *scene)
{
	t_object	*aux;

	while (scene)
	{
		aux = scene;
		scene = scene->next;
		free(aux->params);
		if (aux->color)
			free(aux->color);
		free(aux);
	}
}
