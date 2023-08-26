/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:35 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 13:27:25 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checks(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Error: Todos los argumentos deben ser mayores que 0.\n");
			return (0);
		}
		i++;
	}
	if (argc < 5 || argc > 6)
	{
		printf("Error: Número de argumentos incorrecto.\n");
		return (0);
	}
	return (1);
}

int	ft_check_continuity(t_data *data)
{
	pthread_mutex_lock(&data->checker);
	if (data->aliveness)
	{
		pthread_mutex_unlock(&data->checker);
		return (1);
	}
	pthread_mutex_unlock(&data->checker);
	return (0);
}

static int	is_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (ft_current_time(philo->data) - philo->last_eat
		> philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->data->checker);
		philo->data->aliveness = 0;
		pthread_mutex_unlock(&philo->data->checker);
		ft_print_status(philo, STATUS_DIE);
		return (0);
	}
	pthread_mutex_unlock(&philo->lock);
	return (1);
}

int	ft_check_philos(t_philo **philosophers)
{
	int	i;
	int	full_eat;

	full_eat = 1;
	i = 0;
	while (philosophers[i] != NULL)
	{
		if (!is_philo_alive(philosophers[i]))
			return (1);
		pthread_mutex_lock(&philosophers[i]->data->checker);
		if (philosophers[i]->data->must_eat == 0
			|| philosophers[i]->times_eaten < philosophers[i]->data->must_eat)
			full_eat = 0;
		pthread_mutex_unlock(&philosophers[i]->data->checker);
		i++;
	}
	if (full_eat)
	{
		pthread_mutex_lock(&philosophers[0]->data->checker);
		philosophers[0]->data->aliveness = 0;
		pthread_mutex_unlock(&philosophers[0]->data->checker);
	}
	return (full_eat);
}
