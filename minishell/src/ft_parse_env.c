/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:53:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/18 17:20:54 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	lst_size(t_env *env)
{
	int	i;

	i = 0;
	while (env->next)
	{
		i++;
		env = env->next;
	}
	return (++i);
}

void	ft_parse_list(t_data *data)
{
	char	**envp;
	int		i;
	char	*aux;
	t_env	*auxenv;

	envp = malloc(sizeof(char **) * (lst_size(data->env_variables) + 1));
	if (!envp)
		return ;
	ft_arrcln(data->envp);
	auxenv = data->env_variables;
	i = 0;
	while (auxenv)
	{
		aux = ft_strjoin(auxenv->name, "=");
		envp[i++] = ft_strjoin(aux, auxenv->value);
		free(aux);
		auxenv = auxenv->next;
	}
	envp[i] = 0;
	data->envp = envp;
}

static char	*multi_join(t_env *env, char *str, int i)
{
	size_t	name_len;
	char	*aux_str;
	char	*new_str;

	name_len = ft_env_name_len(&str[i + 1]);
	ft_bzero(&str[i], name_len + 1);
	if (env)
		aux_str = ft_strjoin(str, env->value);
	else
		aux_str = ft_strjoin(str, "");
	i += name_len + 1;
	new_str = ft_strjoin(aux_str, &str[i]);
	return (free(aux_str), new_str);
}

static char	*str_replace_env(t_data *data, char	*str)
{
	char	*new_str;
	char	*aux;
	char	quote;
	int		i;

	new_str = 0;
	i = -1;
	quote = 0;
	while (str[++i])
	{
		quote = ft_check_quote(str[i], quote);
		if (str[i] == '$' && quote != '\'')
		{
			if (str[i + 1] == '?')
			{
				new_str = ft_itoa(data->last);
				break ;
			}
			aux = ft_substr(&str[i + 1], 0, ft_env_name_len(&str[i + 1]));
			new_str = multi_join(ft_get_env(data, aux), str, i);
			free(aux);
			break ;
		}
	}
	return (free(str), new_str);
}

void	ft_parse_env(t_data *data, char	**argv)
{
	int		i;
	int		j;
	char	quotes;

	i = -1;
	quotes = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '"' || argv[i][j] == '\'') && !quotes)
				quotes = argv[i][j];
			else if (argv[i][j] == quotes)
				quotes = 0;
			if (argv[i][j] == '$' && (quotes == '"' || quotes == 0))
				argv[i] = str_replace_env(data, argv[i]);
			if (!argv[i][j])
				break ;
		}
	}
}
