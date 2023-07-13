/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:53:08 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:27:15 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	pa(t_data *data)
{
	t_stack	*aux;

	if (data->stack_b)
	{
		if (!data->stack_a)
		{
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->next = NULL;
		}
		else
		{
			aux = data->stack_a;
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->next = aux;
		}
	}
}

void	pb(t_data *data)
{
	t_stack	*aux;

	if (data->stack_a)
	{
		if (!data->stack_b)
		{
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			data->stack_b->next = NULL;
		}
		else
		{
			aux = data->stack_b;
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			data->stack_b->next = aux;
		}
	}
}
