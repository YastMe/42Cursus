/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:44:50 by abeltran          #+#    #+#             */
/*   Updated: 2023/05/11 18:11:39 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/include/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				current_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

t_stack	*ft_init_stack(int argc, char **argv);
long	ft_atol(const char *str);
int		ft_check_range(char **nums);
void	ft_clean_stack(t_stack *stack);
void	ft_clean_array(char **args);
t_stack	*ft_last_node(t_stack *stack);
int		ft_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_all_numbers(char **args);
int		ft_check_duplicates(t_stack *stack);
void	ft_index(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif
