/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:11:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 15:21:06 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_items(t_list **start)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *start;
	if (!tmp || tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	check_dup(t_data *data)
{
	int	i;
	int	y;

	if (!data->num_i)
		return ;
	i = 0;
	y = i + 1;
	while (i < data->num_str - 1)
	{
		while (y < data->num_str)
		{
			if (data->num_i[i] == data->num_i[y])
				ft_exit(data, 1);
			y++;
		}
		i++;
		y = i + 1;
	}
}

int	ft_already_sorted(t_data *data)
{
	t_list	*tmp;

	tmp = data->start_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_value(t_list **start)
{
	t_list	*tmp;
	t_list	*cmp;
	int		count;

	tmp = *start;
	cmp = *start;
	count = 0;
	while (tmp != NULL)
	{
		while (cmp != NULL)
		{
			if (tmp->content > cmp->content)
				count++;
			cmp = cmp->next;
		}
		tmp->value = count + 1;
		count = 0;
		tmp = tmp->next;
		cmp = *start;
	}
}

void	tmp_value(t_list **start)
{
	t_list	*tmp;
	t_list	*cmp;
	int		count;

	tmp = *start;
	cmp = *start;
	count = 0;
	while (tmp != NULL)
	{
		while (cmp != NULL)
		{
			if (tmp->content > cmp->content)
				count++;
			cmp = cmp->next;
		}
		tmp->tmp_value = count + 1;
		count = 0;
		tmp = tmp->next;
		cmp = *start;
	}
}
