/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:53:45 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 11:47:14 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_void(void)
// {
// 	system("leaks -q philo");
// }

static void	loop(t_data *data)
{
	while (1)
	{
		if (ft_check_philos(data->philosophers))
		{
			break ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_checks(argc, argv))
	{
		ft_init_data(&data, argv);
		ft_philo_creator(&data);
		if (ft_check_continuity(&data))
		{
			ft_philo_starter(&data);
			loop(&data);
		}
		usleep(50);
		ft_clean(&data);
	}		
	return (0);
}
