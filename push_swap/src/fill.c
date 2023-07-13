/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:08:59 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 16:04:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stack_new(char *value)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = ft_atoi(value);
	node->cost_a = 0;
	node->cost_b = 0;
	node->current_pos = -1;
	node->index = -1;
	node->target_pos = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_fill_stack(char **argv)
{
	int		i;
	t_stack	*start;
	t_stack	*current;

	start = NULL;
	i = 0;
	while (argv[i])
	{
		if (!start)
		{
			start = ft_stack_new(argv[i]);
			current = start;
		}
		else
		{
			current->next = ft_stack_new(argv[i]);
			current = current->next;
		}
		i++;
	}
	return (start);
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	char	**nums;
	t_stack	*stack_a;

	nums = NULL;
	stack_a = NULL;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (ft_check_range(nums) && ft_all_numbers(nums))
			stack_a = ft_fill_stack(nums);
		else
			write(2, "Error\n", 7);
		ft_clean_array(nums);
	}
	else
	{
		argv++;
		if (ft_check_range(argv) && ft_all_numbers(argv))
			stack_a = ft_fill_stack(argv);
		else
			write(2, "Error\n", 7);
	}
	return (stack_a);
}

void	ft_index(t_data *data)
{
	int		size;
	t_stack	*highest;
	t_stack	*aux;

	size = ft_stack_size(data->stack_a);
	while (size > 0)
	{
		aux = data->stack_a;
		highest = NULL;
		while (aux)
		{
			if (aux->index == -1)
				if (!highest || aux->value > highest->value)
				highest = aux;
			aux = aux->next;
		}
		if (highest)
			highest->index = size;
		size--;
	}
}
