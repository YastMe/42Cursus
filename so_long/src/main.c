/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:58:23 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 09:41:00 by abeltran         ###   ########.fr       */
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
	atexit(ft_void);
	return (ft_start());
}
