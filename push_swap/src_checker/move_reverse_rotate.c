/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:38:12 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/15 11:58:13 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rra(t_data *data)
{
	t_stack	*penultimate;

	if (data->stack_a && ft_stack_size(data->stack_a) >= 2)
	{
		penultimate = data->stack_a;
		while (penultimate->next->next)
			penultimate = penultimate->next;
		penultimate->next->next = data->stack_a;
		data->stack_a = penultimate->next;
		penultimate->next = NULL;
	}
}

void	rrb(t_data *data)
{
	t_stack	*penultimate;

	if (data->stack_b && ft_stack_size(data->stack_b) >= 2)
	{
		penultimate = data->stack_b;
		while (penultimate->next->next)
			penultimate = penultimate->next;
		penultimate->next->next = data->stack_b;
		data->stack_b = penultimate->next;
		penultimate->next = NULL;
	}
}

void	rrr(t_data *data)
{
	t_stack	*penultimate;

	if (data->stack_a && ft_stack_size(data->stack_a) >= 2)
	{
		penultimate = data->stack_a;
		while (penultimate->next->next)
			penultimate = penultimate->next;
		penultimate->next->next = data->stack_a;
		data->stack_a = penultimate->next;
		penultimate->next = NULL;
	}
	if (data->stack_b && ft_stack_size(data->stack_b) >= 2)
	{
		penultimate = data->stack_b;
		while (penultimate->next->next)
			penultimate = penultimate->next;
		penultimate->next->next = data->stack_b;
		data->stack_b = penultimate->next;
		penultimate->next = NULL;
	}
}
