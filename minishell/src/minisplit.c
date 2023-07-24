/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:03:07 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/18 16:29:57 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	count_args(char *str)
{
	int		i;
	char	quote;
	int		args;

	i = 0;
	args = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (str[i] != ' ' && !quote)
		{
			while (str[i] && str[i] != ' ' && str[i] != quote)
				i++;
			args++;
		}
		else
			i++;
	}
	return (args);
}

static int	get_next_cut(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i] && str[i + 1] && str[i + 1] == ' ')
			return (i);
		else if (quote == str[i])
			quote = 0;
		if (str[i] != ' ' && !quote)
		{
			while (str[i] && str[i] != ' ' && str[i] != quote)
				i++;
			return (i);
		}
		else
			i++;
	}
	return (i);
}

char	**ft_minisplit(char *str)
{
	char	**res;
	int		i;
	int		args;
	char	*aux;

	args = count_args(str);
	res = malloc(sizeof(char *) * (args + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		aux = ft_substr(str, 0, get_next_cut(str) + 1);
		res[i++] = ft_strtrim(aux, " ");
		free(aux);
		if (!str[get_next_cut(str)])
			break ;
		str = &str[get_next_cut(str) + 1];
	}
	res[args] = 0;
	return (res);
}
