/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:22:08 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 13:23:33 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next && aux->next->value > aux->value)
		aux = aux->next;
	if (aux->next == NULL)
		return (1);
	return (0);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*aux;
	int		i;

	aux = stack;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
