/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:54:40 by abeltran          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:37 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = (t_list *) malloc(sizeof(t_list));
	if (aux == NULL)
		return (NULL);
	aux -> content = f(lst->content);
	start = aux;
	while (lst -> next)
	{
		lst = lst -> next;
		aux -> next = (t_list *) malloc(sizeof(t_list));
		if (aux -> next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		aux -> next -> content = f(lst->content);
		aux = aux -> next;
	}
	aux -> next = NULL;
	return (start);
}
