/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:18:57 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/20 22:19:20 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_extension(t_data *data, char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 5)
		ft_error(data, ERR_CUSTOM, "Invalid filename.");
	if (filename[i - 1] != 'b' || filename[i - 2] != 'u'
		|| filename[i - 3] != 'c' || filename[i - 4] != '.')
		ft_error(data, ERR_CUSTOM, "Invalid filename.");
	i = open(filename, O_RDONLY);
	if (i < 0)
		ft_error(data, ERR_SYSTEM, NULL);
	close(i);
}
