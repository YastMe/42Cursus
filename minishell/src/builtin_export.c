/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:58:37 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/20 18:01:45 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	add_to_env(t_data *data, t_env *new_env)
{
	t_env	*current;

	if (!data->env_variables)
	{
		data->env_variables = new_env;
		return ;
	}
	current = data->env_variables;
	while (current->next)
		current = current->next;
	current->next = new_env;
}

static char	*get_env_value(char *raw_string)
{
	size_t	len;
	char	*env_value;
	size_t	index;

	len = 0;
	while (raw_string[len] && raw_string[len] != ' ')
		len++;
	env_value = (char *)malloc((sizeof(char) * len) + 1);
	if (!env_value)
		return ((char *)0);
	index = 0;
	while (index < len)
	{
		env_value[index] = raw_string[index];
		index++;
	}
	env_value[index] = 0;
	return (env_value);
}

static char	*get_env_name(char *raw_string)
{
	int		len;
	char	*env_name;
	size_t	index;

	len = -1;
	while (raw_string[++len])
	{
		if (!((raw_string[len] >= 'a' && raw_string[len] <= 'z')
				|| (raw_string[len] >= 'A' && raw_string[len] <= 'Z')
				|| (raw_string[len] >= '0' && raw_string[len] <= '9')
				|| raw_string[len] == '_'))
			return ((char *) 0);
	}
	len = ft_strlen(raw_string);
	env_name = (char *)malloc((sizeof(char) * len) + 1);
	if (!env_name)
		return ((char *)0);
	index = 0;
	while ((int)index < len)
	{
		env_name[index] = raw_string[index];
		index++;
	}
	env_name[index] = 0;
	return (env_name);
}

static void	env_exists(t_data *data, char *raw_string, char *separator)
{
	t_env	*existing_env;

	existing_env = ft_get_env(data, raw_string);
	free(existing_env->value);
	existing_env->value = get_env_value(separator);
}

int	ft_export(t_data *data, char *raw_string)
{
	char	*separator;
	t_env	*new_env;

	if (!raw_string)
		return (1);
	separator = ft_strchr(raw_string, '=');
	if (!separator)
		return (1);
	*separator = 0;
	if (ft_get_env(data, raw_string))
		return (env_exists(data, raw_string, separator + 1), 1);
	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
		return (1);
	new_env->name = get_env_name(raw_string);
	if (!new_env->name)
		return (free(new_env->name), free(new_env), 1);
	separator++;
	new_env->value = get_env_value(separator);
	new_env->next = 0;
	add_to_env(data, new_env);
	ft_parse_list(data);
	return (0);
}
