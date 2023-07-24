/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:00:47 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/11 12:47:01 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	reset_pwd(t_data *data)
{
	char	*str;
	char	*cwd;

	cwd = getcwd(NULL, PATH_MAX);
	str = ft_strjoin("PWD=", cwd);
	ft_export(data, str);
	free(str);
	free(cwd);
}

static void	reset_oldpwd(t_data *data, t_env *pwd)
{
	char	*str;

	str = ft_strjoin("OLDPWD=", pwd->value);
	ft_export(data, str);
	free(str);
}

static void	check_env(t_data *data)
{
	t_env	*oldpwd;
	t_env	*pwd;

	pwd = ft_get_env(data, "PWD");
	oldpwd = ft_get_env(data, "OLDPWD");
	if (pwd && oldpwd)
		return ;
	else
	{
		if (!pwd)
		{
			reset_pwd(data);
			pwd = ft_get_env(data, "PWD");
		}
		if (!oldpwd)
			reset_oldpwd(data, pwd);
	}
}

int	ft_cd(char *input, t_data *data)
{
	t_env	*oldpwd;
	t_env	*pwd;
	t_env	*home;

	check_env(data);
	pwd = ft_get_env(data, "PWD");
	oldpwd = ft_get_env(data, "OLDPWD");
	home = ft_get_env(data, "HOME");
	if (!input)
	{
		if (chdir(home->value))
			return (1);
	}
	else if (chdir(input))
	{
		printf("minishell: cd: %s: %s%s\n"DEFAULT, input,
			LIGHT_RED, strerror(2));
		return (1);
	}
	free(oldpwd->value);
	oldpwd->value = pwd->value;
	pwd->value = getcwd(NULL, 0);
	ft_parse_list(data);
	return (0);
}
