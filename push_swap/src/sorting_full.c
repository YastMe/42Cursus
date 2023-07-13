/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:30:51 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:44:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_full_b(t_data *data)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(data->stack_a);
	pushed = 0;
	i = 0;
	while (pushed < stack_size / 2 && (stack_size / 2) > 3 && i < stack_size)
	{
		if (data->stack_a->index <= stack_size / 2)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(data);
		pushed++;
	}
}

static void	choose_move(t_stack *node, t_data *data)
{
	if (node->cost_a == 0 && node->cost_b == 0)
		pa(data);
	else if (node->cost_a < 0 && node->cost_b < 0)
		rrr(data);
	else if (node->cost_a > 0 && node->cost_b > 0)
		rr(data);
	else if (node->cost_a < 0)
		rra(data);
	else if (node->cost_a > 0)
		ra(data);
	else if (node->cost_b < 0)
		rrb(data);
	else if (node->cost_b > 0)
		rb(data);
}

static void	sort_full(t_data *data)
{
	t_stack	*node;
	int		size;

	push_full_b(data);
	if (!ft_sorted(data->stack_a))
		ft_sort_three(data);
	while (data->stack_b)
	{
		ft_set_target_pos(data);
		ft_calculate_cost(data);
		node = ft_get_cheapest(data);
		choose_move(node, data);
	}
	size = ft_stack_size(data->stack_a);
	while (!ft_sorted(data->stack_a))
	{
		if (data->stack_a->index > size / 2)
			ra(data);
		else
			rra(data);
	}
}

void	ft_sort(t_data *data)
{
	int	size;

	size = ft_stack_size(data->stack_a);
	if (size == 1)
		return ;
	else if (size == 2 && !ft_sorted(data->stack_a))
		sa(data);
	else if (size == 3 && !ft_sorted(data->stack_a))
		ft_sort_three(data);
	else
		sort_full(data);
}
