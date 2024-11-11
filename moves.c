/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:43 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/26 14:00:53 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next;
	if (*list)
	{
		if ((*list)->next != NULL)
		{
			(*list)->next = tmp->next;
			ft_lstadd_front(list, tmp);
		}
	}
	write (1, "sa\n", 3);
}

void	ft_sb(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next;
	if (*list)
	{
		if ((*list)->next != NULL)
		{
			(*list)->next = tmp->next;
			ft_lstadd_front(list, tmp);
		}
	}
	write (1, "sb\n", 3);
}

void	ft_ss(t_list **list_i, t_list **list_y)
{
	ft_sa(list_i);
	ft_sb(list_y);
}

void	ft_pa(t_list **list_y, t_list **list_i)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list_i;
	tmp2 = *list_y;
	if (*list_i)
	{
		*list_i = tmp->next;
		*list_y = tmp;
		tmp->next = tmp2;
	}
	write (1, "pa\n", 3);
}

void	ft_pb(t_list **list_i, t_list **list_y)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list_i;
	tmp2 = *list_y;
	if (*list_i)
	{
		*list_i = (*list_i)->next;
		*list_y = tmp;
		tmp->next = tmp2;
	}
	write (1, "pb\n", 3);
}
