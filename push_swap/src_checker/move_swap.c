/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:31:46 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:08:42 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sa(t_data *data)
{
	t_stack	*next;

	if (data->stack_a && data->stack_a->next)
	{
		next = data->stack_a->next;
		data->stack_a->next = data->stack_a->next->next;
		next->next = data->stack_a;
		data->stack_a = next;
	}
}

void	sb(t_data *data)
{
	t_stack	*next;

	if (data->stack_b && data->stack_b->next)
	{
		next = data->stack_b->next;
		data->stack_b->next = data->stack_b->next->next;
		next->next = data->stack_b;
		data->stack_b = next;
	}
}

void	ss(t_data *data)
{
	t_stack	*next;

	if (data->stack_a && data->stack_a->next)
	{
		next = data->stack_a->next;
		data->stack_a->next = data->stack_a->next->next;
		next->next = data->stack_a;
		data->stack_a = next;
	}
	if (data->stack_b && data->stack_b->next)
	{
		next = data->stack_b->next;
		data->stack_b->next = data->stack_b->next->next;
		next->next = data->stack_b;
		data->stack_b = next;
	}
}
