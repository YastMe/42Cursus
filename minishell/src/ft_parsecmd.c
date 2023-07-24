/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:23:12 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/20 11:28:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->path = NULL;
	cmd->redir = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*ft_parsecmd(t_data *data)
{
	char	**pipes;
	char	**argv;
	int		i;
	t_cmd	*cmd;

	i = 0;
	if (!ft_isalpha(*data->raw_input) && *data->raw_input != '.'
		&& *data->raw_input != '/' && *data->raw_input != '"'
		&& *data->raw_input != '\'')
		return (NULL);
	pipes = ft_pipesplit(data->raw_input);
	cmd = ft_new_cmd();
	while (pipes[i])
	{
		argv = ft_minisplit(pipes[i]);
		ft_parse_env(data, argv);
		ft_delete_quotes(argv);
		ft_add_cmd(cmd, argv);
		ft_arrcln(argv);
		i++;
	}
	ft_arrcln(pipes);
	return (cmd);
}
