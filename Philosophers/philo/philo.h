/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:53:47 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/26 13:30:18 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERROR_PHILO 1
# define ERROR_FORK 2
# define ERROR_FORK_ARRRAY 3
# define ERROR_WRITER 4
# define ERROR_CHECKER 5

# define ERROR_PHILO_STR "Error al crear filósofo."
# define ERROR_FORK_STR "Error al crear tenedor."
# define ERROR_FORK_ARRRAY_STR "Error al crear array de tenedores."
# define ERROR_WRITER_STR "Error al crear el hilo de escritura."
# define ERROR_CHECKER_STR "Error al crear el hilo de comprobación."

# define STATUS_THINK 1
# define STATUS_SLEEP 2
# define STATUS_TAKE_FORK 3
# define STATUS_EAT 4
# define STATUS_DIE 5

# define RED "\033[0;31m"
# define DEFAULT "\033[;0m"

typedef struct data
{
	pthread_mutex_t	*forks;
	struct s_philo	**philosophers;
	int				philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	long			start_time;
	int				aliveness;
	pthread_mutex_t	writer;
	pthread_mutex_t	checker;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				times_eaten;
	long			last_eat;
	pthread_t		thread;
	pthread_mutex_t	lock;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
}	t_philo;

int		ft_checks(int argc, char **argv);
int		ft_check_continuity(t_data *data);
int		ft_check_philos(t_philo **philosophers);
int		ft_atoi(const char *str);
void	ft_init_data(t_data *data, char **argv);
void	ft_philo_creator(t_data *data);
void	ft_philo_starter(t_data *data);
void	ft_errors(int error, t_data *data);
void	ft_print_status(t_philo *philo, int status);
long	ft_get_time(void);
long	ft_current_time(t_data *data);
void	*ft_general_routine(void *arg);
void	ft_clean(t_data *data);

#endif