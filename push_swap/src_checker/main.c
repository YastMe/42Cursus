/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:06:13 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:29:03 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (0);
	return (1);
}

static int	ft_errors(t_data *data)
{
	if (!data->stack_a)
		return (1);
	if (ft_check_duplicates(data->stack_a))
	{
		ft_clean_stack(data->stack_a);
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}

static void	execute(char *operation, t_data *data)
{
	if (strcmp(operation, "sa\n"))
		sa(data);
	else if (strcmp(operation, "sb\n"))
		sb(data);
	else if (strcmp(operation, "ss\n"))
		ss(data);
	else if (strcmp(operation, "pa\n"))
		pa(data);
	else if (strcmp(operation, "pb\n"))
		pb(data);
	else if (strcmp(operation, "ra\n"))
		ra(data);
	else if (strcmp(operation, "rb\n"))
		rb(data);
	else if (strcmp(operation, "rr\n"))
		rr(data);
	else if (strcmp(operation, "rra\n"))
		rra(data);
	else if (strcmp(operation, "rrb\n"))
		rrb(data);
	else if (strcmp(operation, "rrr\n"))
		rrr(data);
}

static void	checker(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		execute(str, data);
		free(str);
		str = get_next_line(0);
	}
	if (ft_sorted(data->stack_a) && !data->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = ft_init_stack(argc, argv);
		if (!ft_errors(&data))
		{
			ft_index(&data);
			checker(&data);
			ft_clean_stack(data.stack_a);
			ft_clean_stack(data.stack_b);
		}
		else
			return (1);
	}
	return (0);
}
