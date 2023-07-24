/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:40:04 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/21 12:10:13 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_puterr(char *err_msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd(DEFAULT, 2);
	ft_putchar_fd('\n', 2);
}
