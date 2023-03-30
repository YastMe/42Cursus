/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:47:11 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/24 13:25:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include <signal.h>

void	ft_send(int pid, char c)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if (c >> (8 - i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid)
		{
			while (*argv[2])
			{
				ft_send(pid, *argv[2]);
				argv[2]++;
			}
			ft_send(pid, 0);
		}
	}
	return (0);
}
