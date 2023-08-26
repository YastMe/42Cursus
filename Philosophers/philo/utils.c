/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:48:54 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 13:30:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_errors(int error, t_data *data)
{
	if (error == ERROR_PHILO)
		printf("%s\n", ERROR_PHILO_STR);
	else if (error == ERROR_FORK)
		printf("%s\n", ERROR_FORK_STR);
	else if (error == ERROR_FORK_ARRRAY)
		printf("%s\n", ERROR_FORK_ARRRAY_STR);
	else if (error == ERROR_WRITER)
		printf("%s\n", ERROR_WRITER_STR);
	data->aliveness = 0;
}

static void	free_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->checker);
	pthread_mutex_unlock(&philo->data->writer);
}

void	ft_print_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data->checker);
	pthread_mutex_lock(&philo->data->writer);
	if (status == STATUS_DIE)
		philo->data->aliveness = 0;
	if (!philo->data->aliveness && status != STATUS_DIE)
	{
		free_mutex(philo);
		return ;
	}
	pthread_mutex_unlock(&philo->data->checker);
	if (status == STATUS_DIE)
		printf(RED"%ld %d died\n"DEFAULT,
			ft_current_time(philo->data), philo->id);
	else if (status == STATUS_EAT)
		printf("%ld %d is eating\n", ft_current_time(philo->data), philo->id);
	else if (status == STATUS_SLEEP)
		printf("%ld %d is sleeping\n", ft_current_time(philo->data),
			philo->id);
	else if (status == STATUS_THINK)
		printf("%ld %d is thinking\n", ft_current_time(philo->data),
			philo->id);
	else if (status == STATUS_TAKE_FORK)
		printf("%ld %d has taken a fork\n", ft_current_time(philo->data),
			philo->id);
	pthread_mutex_unlock(&philo->data->writer);
}
