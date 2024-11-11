/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:06:55 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/27 12:42:11 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = tmp->next;
	ft_lstadd_back(list, tmp);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = tmp->next;
	ft_lstadd_back(list, tmp);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list **list_i, t_list **list_y)
{
	ft_ra(list_i);
	ft_rb(list_y);
}
