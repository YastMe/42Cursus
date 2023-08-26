/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:52:25 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 13:23:46 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo)
{
	long	timer;

	pthread_mutex_lock(philo->lfork);
	ft_print_status(philo, STATUS_TAKE_FORK);
	pthread_mutex_lock(philo->rfork);
	ft_print_status(philo, STATUS_TAKE_FORK);
	pthread_mutex_lock(&philo->lock);
	philo->last_eat = ft_current_time(philo->data);
	pthread_mutex_unlock(&philo->lock);
	ft_print_status(philo, STATUS_EAT);
	timer = ft_current_time(philo->data) + philo->data->time_to_eat;
	while (ft_current_time(philo->data) <= timer)
	{
		if (!ft_check_continuity(philo->data))
			break ;
		usleep(1);
	}
	pthread_mutex_lock(&philo->lock);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

static void	sleeping(t_philo *philo)
{
	long	wake_up;

	if (philo->data->time_to_sleep == 0)
		return ;
	ft_print_status(philo, STATUS_SLEEP);
	wake_up = ft_current_time(philo->data) + philo->data->time_to_sleep;
	while (ft_current_time(philo->data) < wake_up)
	{
		if (!ft_check_continuity(philo->data))
			break ;
		usleep(1);
	}
}

static void	think(t_philo *philo)
{
	long	thinking_time;

	pthread_mutex_lock(&philo->lock);
	thinking_time = philo->data->time_to_die - ft_current_time(philo->data)
		- philo->last_eat - philo->data->time_to_eat;
	pthread_mutex_unlock(&philo->lock);
	if (thinking_time <= 0)
		thinking_time = 0;
	ft_print_status(philo, STATUS_THINK);
	while (ft_current_time(philo->data) < thinking_time)
	{
		if (!ft_check_continuity(philo->data))
			break ;
		usleep(1);
	}
}

void	*ft_general_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->time_to_die == 0)
		return (NULL);
	while (ft_check_continuity(philo->data))
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}
