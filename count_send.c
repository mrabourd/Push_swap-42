/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_send.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:36:23 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 17:03:28 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_up(t_list **start, t_list *cmp)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!start || !*start || !cmp)
		return (0);
	tmp = *start;
	if (tmp == cmp)
		return (0);
	while (tmp->next != NULL && tmp != cmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_down(t_list *start)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!start)
		return (0);
	tmp = start;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	send_up(t_data *data, int median, int divide, int c)
{
	int	y;

	y = 0;
	while (y < count_up((&data->start_a), get_up(data->start_a, c + median)))
	{
		y++;
	}
	while (y-- > 0)
		ft_ra(&data->start_a);
	if (data->start_a->value < c + median)
	{
		ft_pb(&data->start_a, &data->start_b);
		if (count_items(&data->start_b) > 1)
		{
			if (data->start_b->value < median - (divide / 2))
				ft_rb(&data->start_b);
		}
	}
}

void	send_down(t_data *data, int median, int divide, int c)
{
	int	i;

	i = 0;
	while (i < count_down(get_down(data->start_a, c + median)))
		i++;
	while (i-- >= 1)
		ft_rra(&data->start_a);
	if (data->start_a->value < c + median)
	{
		ft_pb(&data->start_a, &data->start_b);
		if (count_items(&data->start_b) > 1)
		{
			if (data->start_b->value < median - (divide / 2))
				ft_rb(&data->start_b);
		}
	}
}

void	ft_end(t_list **list)
{
	int		i;
	t_list	*small;
	int		c_up;
	int		c_down;

	i = 0;
	small = get_small(*list);
	c_up = count_up(list, small);
	c_down = count_down(small);
	if (c_up <= c_down)
	{
		while (c_up > 0)
		{
			ft_ra(list);
			c_up--;
		}
	}
	else
	{
		while (c_down > 0)
		{
			ft_rra(list);
			c_down--;
		}
	}
}
