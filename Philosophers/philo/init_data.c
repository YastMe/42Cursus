/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:42:24 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 11:46:07 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data, char **argv)
{
	data->start_time = ft_get_time();
	data->aliveness = 1;
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (!data->forks)
		return (ft_errors(ERROR_FORK_ARRRAY, data));
	if (pthread_mutex_init(&data->writer, NULL))
		return (ft_errors(ERROR_WRITER, data));
	if (pthread_mutex_init(&data->checker, NULL))
		return (ft_errors(ERROR_CHECKER, data));
}

static void	create_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (ft_errors(ERROR_FORK, data));
		i++;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		data->philosophers[i]->rfork = &data->forks[i];
		if (i == 0)
			data->philosophers[i]->lfork = &data->forks[data->philo_nbr - 1];
		else
			data->philosophers[i]->lfork = &data->forks[i - 1];
		i++;
	}
}

void	ft_philo_creator(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philosophers)
		return (ft_errors(ERROR_PHILO, data));
	i = 0;
	while (i < data->philo_nbr)
	{
		data->philosophers[i] = malloc(sizeof(t_philo));
		if (!data->philosophers[i])
			return (ft_errors(ERROR_PHILO, data));
		data->philosophers[i]->times_eaten = 0;
		data->philosophers[i]->id = i + 1;
		data->philosophers[i]->last_eat = ft_current_time(data);
		data->philosophers[i]->data = data;
		if (pthread_mutex_init(&data->philosophers[i]->lock, NULL))
			return (ft_errors(ERROR_PHILO, data));
		i++;
	}
	create_forks(data);
}

void	ft_philo_starter(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_create(&data->philosophers[i]->thread, NULL,
				&ft_general_routine, data->philosophers[i]))
			return (ft_errors(ERROR_PHILO, data));
		i++;
		usleep(50);
	}
}
