/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:26:35 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/17 11:09:48 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_redir	*new_redir(int type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = file;
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

static t_redir	*add_back(t_redir *redir, t_redir *node)
{
	t_redir	*aux;

	if (!redir)
		redir = node;
	else
	{
		aux = redir;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
	return (redir);
}

static t_redir	*add_redirs(char **argv)
{
	t_redir	*redirs;
	char	*aux;

	redirs = NULL;
	while (*argv)
	{
		aux = ft_strtrim(*argv, " ");
		if (ft_strnstr(aux, "<<", 2))
			redirs = add_back(redirs, new_redir(DR_IN,
						ft_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, ">>", 2))
			redirs = add_back(redirs, new_redir(DR_OUT,
						ft_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, "<", 1))
			redirs = add_back(redirs, new_redir(R_IN,
						ft_strtrim(argv[1], " ")));
		else if (ft_strnstr(aux, ">", 1))
			redirs = add_back(redirs, new_redir(R_OUT,
						ft_strtrim(argv[1], " ")));
		argv++;
		free(aux);
	}
	return (redirs);
}

static char	**get_argv(char **argv)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	while (argv[i] && !ft_strnstr(argv[i], ">>", 2)
		&& !ft_strnstr(argv[i], ">>", 2) && !ft_strnstr(argv[i], ">", 1)
		&& !ft_strnstr(argv[i], "<", 1))
		i++;
	ret = malloc(sizeof(char **) * (i + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ret[j] = ft_strtrim(argv[j], " ");
		j++;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_add_cmd(t_cmd *cmd, char **argv)
{
	if (cmd->argv != NULL)
	{
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_new_cmd();
		cmd = cmd->next;
	}
	cmd->argv = get_argv(argv);
	cmd->path = ft_strtrim(argv[0], " ");
	cmd->redir = add_redirs(argv);
}
