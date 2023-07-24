/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:14:16 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/18 17:20:53 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	ft_valid_env_name(char *name)
{
	if (!name || !*name)
		return (false);
	while (*name)
	{
		if (!(ft_isalnum(*name) || *name == '_'))
			return (false);
		name++;
	}
	return (true);
}

size_t	ft_env_name_len(char *name)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(name[len]) || name[len] == '_')
		len++;
	return (len);
}

t_env	*ft_get_env(t_data *data, char *name)
{
	t_env	*current;

	current = data->env_variables;
	if (!current)
		return ((t_env *) 0);
	while (current->next)
	{
		if (ft_strcmp(name, current->name))
			return (current);
		current = current->next;
	}
	if (ft_strcmp(name, current->name))
		return (current);
	return ((t_env *) 0);
}

char	ft_check_quote(char c, char quote)
{
	if (c == '\'' && !quote)
		return ('\'');
	else if (c == '\'')
		return (0);
	else if (c == '"' && !quote)
		return ('"');
	else if (c == '"')
		return (0);
	else
		return (quote);
}
