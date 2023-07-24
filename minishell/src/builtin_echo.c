/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:11:51 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/05 11:24:55 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_echo(t_data data)
{
	int		endl;
	int		i;

	i = 1;
	endl = 1;
	if (data.cmd->argv[i])
	{
		while (data.cmd->argv[i] && !ft_strncmp(data.cmd->argv[i], "-n", 2))
		{
			i++;
			endl = 0;
		}
		while (data.cmd->argv[i])
		{
			printf("%s ", data.cmd->argv[i++]);
		}
	}
	if (endl)
		printf("\n");
	return (0);
}
