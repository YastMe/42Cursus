/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:01:19 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/19 12:32:41 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	keep_going(char *str, int i, char quote)
{
	while (str[i] && quote && str[i] != quote)
		i++;
	return (i);
}

static int	*get_range(char	*str)
{
	int		i;
	int		*range;
	char	quote;

	i = 0;
	quote = 0;
	range = ft_calloc(sizeof(int), 2);
	while (range && i < (int) ft_strlen(str))
	{
		if (str[i] && !quote && (str[i] == '"' || str[i] == '\''))
		{
			quote = str[i];
			range[0] = i++;
		}
		else if (quote && (str[i] == '"' || str[i] == '\''))
		{
			range[1] = i;
			return (range);
		}
		if (quote)
			i = keep_going(str, i, quote);
		else
			i++;
	}
	return (free(range), NULL);
}

static char	*triquote(char *str, int *range)
{
	char	*start;
	char	*inter;
	char	*end;

	start = ft_substr(str, 0, range[0]);
	inter = ft_substr(str, range[0] + 1, range[1] - range[0] - 1);
	end = ft_substr(str, range[1] + 1, ft_strlen(str) - range[1]);
	free(str);
	str = ft_strjoin(inter, end);
	free(inter);
	free(end);
	end = ft_strjoin(start, str);
	free(start);
	free(str);
	return (end);
}

static char	*copy_str(char *str, int *range)
{
	char	*aux;
	char	*inter;
	int		len;

	len = ft_strlen(str) - 1;
	if (range[0] == 0 && range[1] == len)
	{
		aux = ft_substr(str, 1, range[1] - 1);
		return (free(str), aux);
	}
	else if (range[0] == 0 && range[1] < len)
	{
		aux = ft_substr(str, 1, range[1] - 1);
		inter = ft_substr(str, range[1] + 1, len - range[1]);
	}
	else if (range[1] == len)
	{
		aux = ft_substr(str, 0, range[0]);
		inter = ft_substr(str, range[0] + 1, range[1] - range[0] - 1);
	}
	else
		return (triquote(str, range));
	free(str);
	str = ft_strjoin(aux, inter);
	return (free(aux), free(inter), str);
}

char	**ft_delete_quotes(char **argv)
{
	int		i;
	int		*range;
	int		end;
	char	*str;

	i = 0;
	while (argv[i])
	{
		range = get_range(argv[i]);
		while (range)
		{
			end = range[1];
			str = copy_str(argv[i], range);
			free(range);
			argv[i] = str;
			range = get_range(&argv[i][end - 1]);
			if (range)
			{
				range[0] += (ft_strlen(str) - ft_strlen(&str[end]) - 1);
				range[1] += (ft_strlen(str) - ft_strlen(&str[end]) - 1);
			}
		}
		i++;
	}
	return (argv);
}
