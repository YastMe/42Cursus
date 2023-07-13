/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:08:29 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/03 12:28:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_positions(t_stack *stack)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux->current_pos = i;
		i++;
		aux = aux->next;
	}
}

static int	get_target(t_stack *stack, int b_index, int t_index, int target)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		if (aux->index > b_index && aux->index < t_index)
		{
			t_index = aux->index;
			target = aux->current_pos;
		}
		aux = aux->next;
	}
	if (t_index != INT_MAX)
		return (target);
	aux = stack;
	while (aux)
	{
		if (aux->index < t_index)
		{
			t_index = aux->index;
			target = aux->current_pos;
		}
		aux = aux->next;
	}
	return (target);
}

void	ft_set_target_pos(t_data *data)
{
	t_stack	*aux;
	int		target;

	aux = data->stack_b;
	set_positions(data->stack_a);
	set_positions(data->stack_b);
	target = 0;
	while (aux)
	{
		target = get_target(data->stack_a, aux->index, INT_MAX, target);
		aux->target_pos = target;
		aux = aux->next;
	}
}
