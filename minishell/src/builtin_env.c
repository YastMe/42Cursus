/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:55:04 by abeltran          #+#    #+#             */
/*   Updated: 2023/06/21 10:58:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux && aux->next)
	{
		printf("%s=%s\n", aux->name, aux->value);
		aux = aux->next;
	}
	if (aux)
		printf("%s=%s\n", aux->name, aux->value);
	return (0);
}
