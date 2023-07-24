/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:51:13 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/17 13:11:27 by abeltran         ###   ########.fr       */
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
			quote = str[i++];
		while (str[i] && quote && str[i] != quote && str[i + 1])
			i++;
		if (quote == str[i])
			quote = 0;
		if (str[i] == '|')
			args++;
		if (str[i])
			i++;
	}
	return (args + 1);
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
			quote = str[i++];
		while (str[i] && quote && str[i] != quote && str[i + 1])
			i++;
		if (quote == str[i])
			quote = 0;
		if (str[i] == '|')
			return (i);
		if (str[i])
			i++;
	}
	return (i);
}

char	**ft_pipesplit(char *str)
{
	char	**res;
	int		i;
	int		args;

	args = count_args(str);
	res = malloc(sizeof(char *) * (args + 1));
	if (!res)
		return (NULL);
	res[args] = 0;
	i = 0;
	while (*str)
	{
		res[i] = ft_substr(str, 0, get_next_cut(str));
		if (!str[get_next_cut(str)])
			break ;
		str = &str[get_next_cut(str) + 1];
		i++;
	}
	return (res);
}
