/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:21:22 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/19 23:08:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*join_and_free(char	*s1, char	*s2)
{
	char	*ret_str;

	ret_str = ft_strjoin(s1, s2);
	free(s1);
	return (ret_str);
}

static bool	check_env(t_data *data, char **home, char **pwd)
{
	if (!ft_get_env(data, "HOME") || !ft_get_env(data, "PWD"))
		return (false);
	*home = ft_get_env(data, "HOME")->value;
	*pwd = ft_get_env(data, "PWD")->value;
	if (!ft_get_env(data, "USER"))
		return (false);
	return (true);
}

static char	*get_entry(t_data *data)
{
	char	*str_entry;
	char	*aux_str;
	char	*home;
	char	*pwd;

	if (!check_env(data, &home, &pwd))
		return (ft_strdup(LIGHT_GREEN"minishell"DEFAULT"$ "));
	aux_str = ft_strjoin(LIGHT_GREEN, ft_get_env(data, "USER")->value);
	str_entry = join_and_free(aux_str, DEFAULT":");
	if (ft_strncmp(home, pwd, ft_strlen(home)) == 0)
		aux_str = join_and_free(str_entry, LIGHT_BLUE"~");
	else
	{
		aux_str = join_and_free(str_entry, LIGHT_BLUE);
		str_entry = join_and_free(aux_str, pwd);
		aux_str = join_and_free(str_entry, DEFAULT"$ ");
		return (aux_str);
	}
	if (ft_strcmp(home, pwd))
		return (join_and_free(aux_str, DEFAULT"$ "));
	else
	{
		str_entry = join_and_free(aux_str, pwd + ft_strlen(home));
		return (join_and_free(str_entry, DEFAULT"$ "));
	}
}

int	ft_read_input(t_data *data)
{
	char	*str_entry;
	char	*aux;

	str_entry = get_entry(data);
	if (data->raw_input)
	{
		free(data->raw_input);
		data->raw_input = NULL;
	}
	aux = readline(str_entry);
	if (!aux)
	{
		printf("\n");
		ft_exit(data);
		return (free(aux), free(str_entry), 0);
	}
	data->raw_input = ft_strtrim(aux, " \t");
	free(aux);
	if (!data->raw_input)
		return (0);
	else if (*(data->raw_input))
		add_history(data->raw_input);
	free(str_entry);
	return (1);
}
