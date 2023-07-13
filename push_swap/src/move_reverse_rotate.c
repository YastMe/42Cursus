/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:38:12 by abeltran          #+#    #+#             */
/*   Updated: 2023/04/28 14:44:59 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_data *data)
{
	t_stack	*penultimate;

	penultimate = data->stack_a;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next->next = data->stack_a;
	data->stack_a = penultimate->next;
	penultimate->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	t_stack	*penultimate;

	penultimate = data->stack_b;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next->next = data->stack_b;
	data->stack_b = penultimate->next;
	penultimate->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	t_stack	*penultimate;

	penultimate = data->stack_a;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next->next = data->stack_a;
	data->stack_a = penultimate->next;
	penultimate->next = NULL;
	penultimate = data->stack_b;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next->next = data->stack_b;
	data->stack_b = penultimate->next;
	penultimate->next = NULL;
	write(1, "rrr\n", 4);
}
