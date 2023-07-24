/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:15:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/19 17:32:45 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	welcome(void)
{
	printf("                \033[0;32mWelcome to\033[;0m\n\
\033[0;36m           _       _ _    _ ______ _      _      \n\
\033[1;34m          (_)     (_| |  | |  ____| |    | |     \n\
\033[0;34m _ __ ___  _ _ __  _| |__| | |__  | |    | |     \n\
\033[1;35m| '_ ` _ \\| | '_ \\| |  __  |  __| | |    | |     \n\
\033[0;35m| | | | | | | | | | | |  | | |____| |____| |____ \n\
\033[0;31m|_| |_| |_|_|_| |_|_|_|  |_|______|______|______|\n\n");
}

static void	update_lvl(t_data *data)
{
	char	*lvl;
	char	*str;
	char	*final_str;
	int		i;

	lvl = ft_get_env(data, "SHLVL")->value;
	i = ft_atoi(lvl) + 1;
	lvl = ft_itoa(i);
	str = ft_strdup("SHLVL=");
	final_str = ft_strjoin(str, lvl);
	ft_export(data, final_str);
	free(lvl);
	free(str);
	free(final_str);
	ft_cd(NULL, data);
}

static void	update_name(t_data *data)
{
	char	*name;
	char	*str;
	char	*final_str;

	str = ft_strdup("SHELL=");
	name = ft_strdup("minishell");
	final_str = ft_strjoin(str, name);
	ft_export(data, final_str);
	free(str);
	free(name);
	free(final_str);
}

int	ft_init_data(t_data	*data, char **envp)
{
	data->raw_input = 0;
	data->env_variables = 0;
	data->heredoc = 0;
	data->envp = NULL;
	data->cmd = NULL;
	ft_init_signals();
	while (*envp)
		ft_export(data, *envp++);
	data->exit = false;
	update_lvl(data);
	update_name(data);
	welcome();
	return (1);
}
