/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:36:13 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/23 14:20:21 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (((*lst)->content > (*lst)->next->content)
		|| ((*lst)->next->content > (*lst)->next->next->content))
	{
		if ((*lst)->content > (*lst)->next->content)
			first_is_sup(lst);
		else if ((*lst)->content < (*lst)->next->content)
			first_is_inf(lst);
	}
}

void	first_is_sup(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->content < (*lst)->next->next->content)
		ft_sa(lst);
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content > (*lst)->next->next->content)
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	if ((*lst)->content > (*lst)->next->next->content
		&& (*lst)->content > (*lst)->next->content)
		ft_ra(lst);
}

void	first_is_inf(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if ((*lst)->content < (*lst)->next->content
		&& (*lst)->content > (*lst)->next->next->content)
		ft_rra(lst);
	if ((*lst)->next->content > (*lst)->next->next->content)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
}

void	ft_two(t_list **lst)
{
	if (((*lst)->content > (*lst)->next->content))
		ft_sa(lst);
}
