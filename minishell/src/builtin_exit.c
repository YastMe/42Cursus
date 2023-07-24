/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:15:40 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/21 12:47:53 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_exit(t_data *data)
{
	ft_putendl_fd("exit", 1);
	data->exit = true;
	if (data->cmd)
		ft_clean_cmd(data);
	ft_clean_env(data);
	ft_arrcln(data->envp);
	return (0);
}
