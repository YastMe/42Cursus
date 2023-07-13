/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:54:01 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/03 12:31:28 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = data->stack_a->value;
	y = data->stack_a->next->value;
	z = data->stack_a->next->next->value;
	if (x > y && x < z && y < z)
		sa(data);
	else if (x > y && x > z && y < z)
		ra(data);
	else if (x < y && x > z && y > z)
		rra(data);
	else if (x > y && x > z && y > z)
	{
		sa(data);
		rra(data);
	}
	else
	{
		sa(data);
		ra(data);
	}
}
