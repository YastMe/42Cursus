/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:40:08 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/12 13:42:27 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clean_stack(t_stack *stack)
{
	t_stack	*node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

void	ft_clean_array(char **args)
{
	int	i;

	if (args)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}	
}
