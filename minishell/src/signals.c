/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:31:46 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/20 11:38:54 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	g_signal_flag = 0;

static void	handler_int(int signal)
{
	(void) signal;
	ft_putendl_fd("", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_signal_flag == 0)
		rl_redisplay();
}

void	ft_set_flag(int i)
{
	g_signal_flag = i;
}

void	ft_init_signals(void)
{
	signal(SIGINT, handler_int);
	signal(SIGQUIT, SIG_IGN);
}
