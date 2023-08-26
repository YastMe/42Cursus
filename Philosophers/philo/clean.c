/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:16:41 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 11:43:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_nbr == 1)
	{
		pthread_kill(data->philosophers[0]->thread, 0);
		return ;
	}
	while (i < data->philo_nbr)
	{
		pthread_join(data->philosophers[i]->thread, NULL);
		i++;
	}
}

static void	free_philo_array(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(&data->philosophers[i]->lock);
		free(data->philosophers[i++]);
	}
	free(data->philosophers);
}

static void	destroy_data_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	pthread_mutex_destroy(&data->checker);
	pthread_mutex_destroy(&data->writer);
}

void	ft_clean(t_data *data)
{
	join_threads(data);
	free_philo_array(data);
	destroy_data_mutex(data);
}
