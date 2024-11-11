/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:39:47 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/26 18:32:41 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_median(t_data *data, int max, int divide)
{
	t_list	*tmp;
	int		c;

	c = 0;
	if (data->start_b != NULL)
		c = count_items(&data->start_b);
	tmp = data->start_a;
	while (check_under_median(data->start_a, c + max) == 1)
	{
		if (count_up(&data->start_a, get_up(data->start_a, max)) == 0)
		{
			send_up(data, max, divide, c);
		}
		else if (count_up(&data->start_a, get_up(data->start_a, max))
			<= count_down(get_down(data->start_a, max)))
		{
			send_up(data, max, divide, c);
		}
		else if (count_up(&data->start_a, get_up(data->start_a, max))
			> count_down(get_down(data->start_a, max)))
		{
			send_down(data, max, divide, c);
		}
	}
}

void	send_big(t_data *data, int max, int divide)
{
	t_list	*tmp;
	int		c;

	c = 0;
	tmp = data->start_a;
	while (check_under_median(data->start_a, max) == 1)
	{
		if (count_up(&data->start_a, get_up(data->start_a, max)) == 0)
		{
			ft_pb(&data->start_a, &data->start_b);
			if (data->start_b->value < max - (divide / 2))
				ft_rb(&data->start_b);
		}
		else if (count_up(&data->start_a, get_up(data->start_a, max))
			<= count_down(get_down(data->start_a, max)))
		{
			send_up(data, max, divide, c);
		}
		else if (count_up(&data->start_a, get_up(data->start_a, max))
			> count_down(get_down(data->start_a, max)))
		{
			send_down(data, max, divide, c);
		}
	}
}

void	ft_sort(t_data *data)
{
	int		max;

	max = 0;
	if (count_items(&data->start_a) > 10)
	{
		data->divide = count_items(&data->start_a) / 10;
		while (count_items(&data->start_a) > data->divide / 2)
		{
			max = max + data->divide;
			send_big(data, max, data->divide);
		}
	}
	data->divide = 2;
	while (count_items(&data->start_a) > 3)
	{
		max = count_items(&data->start_a) / 2;
		send_median(data, max, data->divide);
	}
	if (count_items(&data->start_a) == 2)
		ft_two(&data->start_a);
	if (count_items(&data->start_a) == 3)
		ft_three(&data->start_a);
	while (count_items(&data->start_b) > 0)
		b_to_a(&data->start_b, data);
	ft_end(&data->start_a);
}

int	check_under_median(t_list *list, int median)
{
	t_list	*tmp;

	if (!list)
		return (0);
	tmp = list;
	while (tmp)
	{
		if (tmp->value < median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
