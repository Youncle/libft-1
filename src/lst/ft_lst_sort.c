/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_swap(t_list **current)
{
	t_list	*tmp;

	tmp = (*current)->next->next;
	(*current)->next->next = (*current);
	(*current)->next = tmp;
}

void		ft_lst_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*last;

	current = *begin_list;
	if (!*begin_list)
		return ;
	while (current->next)
	{
		if ((*cmp)(current->content, current->next->content) > 0)
		{
			if (current != *begin_list)
				last->next = current->next;
			else
				*begin_list = current->next;
			ft_lst_swap(&current);
			current = *begin_list;
		}
		else
		{
			last = current;
			current = current->next ? current->next : current;
		}
	}
}
