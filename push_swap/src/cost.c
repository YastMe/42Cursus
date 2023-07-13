/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:52:35 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 16:57:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_calculate_cost(t_data *data)
{
	t_stack	*aux;
	int		sizea;
	int		sizeb;

	aux = data->stack_b;
	sizea = ft_stack_size(data->stack_a);
	sizeb = ft_stack_size(data->stack_b);
	while (aux)
	{
		aux->cost_b = aux->current_pos;
		if (aux->current_pos > sizeb / 2)
			aux->cost_b = (sizeb - aux->current_pos) * -1;
		aux->cost_a = aux->target_pos;
		if (aux->target_pos > sizea / 2)
			aux->cost_a = (sizea - aux->target_pos) * -1;
		aux = aux->next;
	}
}

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

t_stack	*ft_get_cheapest(t_data *data)
{
	t_stack	*aux;
	t_stack	*cheap;

	aux = data->stack_b;
	cheap = aux;
	while (aux)
	{
		if (ft_abs(aux->cost_b) + ft_abs(aux->cost_a)
			< ft_abs(cheap->cost_b) + ft_abs(cheap->cost_a))
			cheap = aux;
		aux = aux->next;
	}
	return (cheap);
}
