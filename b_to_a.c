/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:23:22 by mrabourd          #+#    #+#             */
/*   Updated: 2023/01/26 17:17:56 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_up_btoa(t_data *data, t_list *send)
{
	int	y;

	y = 0;
	while (y < count_up((&data->start_b), send))
		y++;
	while (y-- > 0)
		ft_rb(&data->start_b);
	ft_pa(&data->start_a, &data->start_b);
}

void	send_down_btoa(t_data *data, t_list *send)
{
	int	y;

	y = 0;
	while (y < count_down(send))
		y++;
	while (y-- > 0)
		ft_rrb(&data->start_b);
	ft_pa(&data->start_a, &data->start_b);
}

void	b_to_a_up(t_data *data, t_list *big, t_list *small)
{
	if (count_up(&data->start_b, small) <= count_items(&data->start_b) / 2)
	{
		if (count_up(&data->start_b, big) < count_up(&data->start_b, small))
			send_up_btoa(data, big);
		else
		{
			send_up_btoa(data, small);
			ft_ra(&data->start_a);
		}
	}
	else
	{
		if (count_up(&data->start_b, big) < count_down(small))
			send_up_btoa(data, big);
		else
		{
			send_down_btoa(data, small);
			ft_ra(&data->start_a);
		}
	}
}

void	b_to_a_down(t_data *data, t_list *big, t_list *small)
{
	if (count_up(&data->start_b, small) <= count_items(&data->start_b) / 2)
	{
		if (count_up(&data->start_b, small) < count_down(big))
		{
			send_up_btoa(data, small);
			ft_ra(&data->start_a);
		}
		else
			send_down_btoa(data, big);
	}
	else
	{
		if (count_down(big) < count_down(small))
			send_down_btoa(data, big);
		else
		{
			send_down_btoa(data, small);
			ft_ra(&data->start_a);
		}
	}
}

void	b_to_a(t_list **list, t_data *data)
{
	t_list	*big;
	t_list	*small;
	t_list	*tmp;
	int		up;
	int		down;

	tmp_value(&data->start_b);
	big = get_big(*list, count_items(&data->start_b));
	small = get_small(*list);
	up = 0;
	down = 0;
	tmp = *list;
	if (count_up(&data->start_b, big) <= count_items(&data->start_b) / 2)
		b_to_a_up(data, big, small);
	else
		b_to_a_down(data, big, small);
}
