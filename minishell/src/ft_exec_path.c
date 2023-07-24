/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:44:30 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/19 20:08:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	search_path(t_data *data, t_cmd *execute)
{
	int		i;
	char	*aux_str;
	char	*path_bin;
	char	**path_env;

	i = -1;
	path_bin = 0;
	path_env = ft_split(ft_get_env(data, "PATH")->value, ':');
	while (path_env[++i])
	{
		if (path_bin)
			free(path_bin);
		aux_str = ft_strjoin(path_env[i], "/");
		path_bin = ft_strjoin(aux_str, execute->path);
		free(aux_str);
		execve(path_bin, execute->argv, data->envp);
	}
	if (path_bin)
		free(path_bin);
	return (ft_arrcln(path_env), ft_puterr("command not found"), exit(1));
}

void	ft_exec_path(t_data *data, t_cmd *execute)
{
	ft_set_flag(1);
	if (execute->next)
		ft_exec_builtin(data, execute, false, false);
	if (execute->path[0] == '.' || execute->path[0] == '/')
		execve(execute->path, execute->argv, data->envp);
	if (!ft_get_env(data, "PATH"))
		return (ft_puterr("command not found"), exit(EXIT_FAILURE));
	search_path(data, execute);
}
