/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prerequisites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:11:06 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 13:28:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_all_numbers(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!(ft_isdigit(args[i][j])
				|| ((args[i][j] == '-' || args[i][j] == '+') && args[i][j + 1]
				&& ft_isdigit(args[i][j + 1]))))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_range(char **nums)
{
	long	n;

	while (*nums)
	{
		n = ft_atol(*nums);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		nums++;
	}
	return (1);
}

static int	check_array(int *nums, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (nums[i] == nums[j])
				count++;
			j++;
		}
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicates(t_stack *stack)
{
	int		*nums;
	int		size;
	int		i;
	int		dupes;
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		size = ft_stack_size(stack);
		nums = (int *) malloc(sizeof(int *) * size);
		if (!nums)
			return (0);
		i = 0;
		while (aux)
		{
			nums[i] = aux->value;
			aux = aux->next;
			i++;
		}
		dupes = check_array(nums, size);
		free(nums);
		return (dupes);
	}
	return (0);
}
