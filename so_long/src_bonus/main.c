/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:58:23 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 14:51:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// void	ft_void(void)
// {
// 	system("leaks -q so_long");
// }

int	ft_ber(char	*file)
{
	char	*aux;

	aux = file;
	while (*aux)
		aux++;
	while (file < aux)
	{
		if (*aux == '.')
			if (*aux + 1 && *aux + 2 && *aux + 3)
				if (aux[1] == 'b' && aux[2] == 'e' && aux[3] == 'r')
					return (1);
		aux--;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	int	fd;

	if (argc == 2)
	{
		if (ft_ber(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
			{
				ft_printf("Map file not found.\n");
				return (-1);
			}
			close(fd);
			return (ft_start(argv[1]));
		}
		else
			ft_printf("Please provide a .ber file\n");
	}
	else if (argc > 2)
		ft_printf("Please provide only one map file.\n");
	else
		ft_printf("Please provide a map file.\n");
	return (-1);
}
