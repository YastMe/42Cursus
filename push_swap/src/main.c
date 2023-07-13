/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:50 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:46:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	ft_void(void)
// {
// 	system("leaks -q push_swap");
// }

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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = ft_init_stack(argc, argv);
		if (!ft_errors(&data) && !ft_sorted(data.stack_a))
		{
			ft_index(&data);
			ft_sort(&data);
			ft_clean_stack(data.stack_a);
			ft_clean_stack(data.stack_b);
		}
		else
			return (1);
	}
	return (0);
}
