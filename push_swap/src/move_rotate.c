/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:49:03 by abeltran          #+#    #+#             */
/*   Updated: 2023/04/28 14:52:36 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_data *data)
{
	t_stack	*last;

	last = ft_last_node(data->stack_a);
	last->next = data->stack_a;
	data->stack_a = data->stack_a->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	t_stack	*last;

	last = ft_last_node(data->stack_b);
	last->next = data->stack_b;
	data->stack_b = data->stack_b->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	t_stack	*last;

	last = ft_last_node(data->stack_a);
	last->next = data->stack_a;
	data->stack_a = data->stack_a->next;
	last->next->next = NULL;
	last = ft_last_node(data->stack_b);
	last->next = data->stack_b;
	data->stack_b = data->stack_b->next;
	last->next->next = NULL;
	write(1, "rr\n", 3);
}
