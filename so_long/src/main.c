/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:58:23 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/09 20:30:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void	ft_void(void)
{
	system("leaks -q so_long");
}

int	main(void)
{
	int	result;
	atexit(ft_void);
	result = ft_start();
	if (result == EXIT_FAILURE)
		ft_printf("Ha ocurrido un error.\n");
	return (result);
}
