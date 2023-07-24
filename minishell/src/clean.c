/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:34:44 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/17 13:14:10 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_clean_child(t_data *data)
{
	ft_clean_cmd(data);
	ft_clean_env(data);
}

void	ft_clean_env(t_data *data)
{
	t_env	*node;

	while (data->env_variables)
	{
		node = data->env_variables;
		data->env_variables = data->env_variables->next;
		free(node->name);
		free(node->value);
		free(node);
	}
}

void	ft_arrcln(char	**array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}	
}

void	ft_clean_cmd(t_data *data)
{
	t_cmd	*aux;
	t_redir	*raux;

	while (data->cmd)
	{
		aux = data->cmd;
		data->cmd = data->cmd->next;
		free(aux->path);
		ft_arrcln(aux->argv);
		while (aux->redir)
		{
			raux = aux->redir;
			aux->redir = aux->redir->next;
			free(raux->file);
			free(raux);
		}
		free(aux);
	}
}
