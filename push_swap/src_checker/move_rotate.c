/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:49:03 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/15 11:58:44 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ra(t_data *data)
{
	t_stack	*last;

	if (data->stack_a && ft_stack_size(data->stack_a) >= 2)
	{
		last = ft_last_node(data->stack_a);
		last->next = data->stack_a;
		data->stack_a = data->stack_a->next;
		last->next->next = NULL;
	}
}

void	rb(t_data *data)
{
	t_stack	*last;

	if (data->stack_b && ft_stack_size(data->stack_b) >= 2)
	{
		last = ft_last_node(data->stack_b);
		last->next = data->stack_b;
		data->stack_b = data->stack_b->next;
		last->next->next = NULL;
	}
}

void	rr(t_data *data)
{
	t_stack	*last;

	if (data->stack_a && ft_stack_size(data->stack_a) >= 2)
	{
		last = ft_last_node(data->stack_a);
		last->next = data->stack_a;
		data->stack_a = data->stack_a->next;
		last->next->next = NULL;
	}
	if (data->stack_b && ft_stack_size(data->stack_b) >= 2)
	{
		last = ft_last_node(data->stack_b);
		last->next = data->stack_b;
		data->stack_b = data->stack_b->next;
		last->next->next = NULL;
	}
}
