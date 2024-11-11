/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:17:42 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 17:03:07 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_up(t_list *list, int median)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->value >= median && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->value < median)
	{
		return (tmp);
	}
	return (tmp);
}

t_list	*get_down(t_list *list, int median)
{
	t_list	*tmp;
	t_list	*ref_down;

	if (!list)
		return (NULL);
	tmp = list;
	ref_down = NULL;
	while (tmp != NULL && tmp)
	{
		if (tmp->value <= median)
			ref_down = tmp;
		if (tmp->next == NULL)
			return (ref_down);
		else
			tmp = tmp->next;
	}
	return (ref_down);
}

t_list	*get_big(t_list *list, int sup_value)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->tmp_value < sup_value && tmp != NULL)
		tmp = tmp->next;
	if (tmp->tmp_value == sup_value)
		return (tmp);
	return (tmp);
}

t_list	*get_small(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->tmp_value == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
