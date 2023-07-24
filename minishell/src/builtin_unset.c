/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:40:56 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/20 18:04:53 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_env	*get_next_env(t_data *data, char *name)
{
	t_env	*current;

	current = data->env_variables;
	while (current->next)
	{
		if (ft_strcmp(current->name, name))
			return (current->next);
		current = current->next;
	}
	if (ft_strcmp(current->name, name))
		return (current->next);
	return ((t_env *) 0);
}

static t_env	*get_previous_env(t_data *data, char *name)
{
	t_env	*current;

	current = data->env_variables;
	while (current->next)
	{
		if (ft_strcmp(current->next->name, name))
			return (current);
		current = current->next;
	}
	return ((t_env *)0);
}

int	ft_unset(t_data *data, char *raw_string)
{
	t_env	*delete;
	t_env	*prev;
	t_env	*next;

	if (!raw_string)
		return (1);
	delete = ft_get_env(data, raw_string);
	if (!delete)
		return (1);
	prev = get_previous_env(data, raw_string);
	next = get_next_env(data, raw_string);
	if (!prev)
		data->env_variables = next;
	else
		prev->next = next;
	if (delete->next == NULL)
		prev->next = NULL;
	free(delete->name);
	free(delete->value);
	free(delete);
	ft_parse_list(data);
	return (0);
}
