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

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	context = NULL;
	if (!info)
		return ;
	if (SIGUSR1 == signal)
		c = c << 1;
	else if (SIGUSR2 == signal)
		c = c << 1 | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
