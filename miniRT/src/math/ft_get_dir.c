/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:37:18 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/25 19:24:00 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vector	ft_get_dir(t_data *data, t_vector *coord)
{
	t_vector	new_vector;

	ft_vector_init(&new_vector, coord->i, coord->j, data->forward.k);
	new_vector = ft_vector_normalize(&new_vector);
	return (new_vector);
}
