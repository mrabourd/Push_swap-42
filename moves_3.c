/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:04:37 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/27 12:42:00 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **list)
{
	t_list	*start;
	t_list	*tmp;

	start = *list;
	while (start->next->next != NULL)
		start = start->next;
	tmp = start->next;
	start->next = NULL;
	ft_lstadd_front(list, tmp);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list **list)
{
	t_list	*start;
	t_list	*tmp;

	start = *list;
	while (start->next->next != NULL)
		start = start->next;
	tmp = start->next;
	start->next = NULL;
	ft_lstadd_front(list, tmp);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_list **list_i, t_list **list_y)
{
	ft_rra(list_i);
	ft_rrb(list_y);
}
