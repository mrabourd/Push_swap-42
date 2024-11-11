/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:59:05 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 15:31:02 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free (tmp);
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstadd_back(t_list **start, t_list *new)
{
	t_list	*tmp;

	tmp = *start;
	if (start && *start)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (start)
		*start = new;
	if (new)
		new->next = NULL;
	else
		return (1);
	return (0);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->content = content;
	new->value = -1;
	new->tmp_value = -1;
	return (new);
}

void	create_list(t_data *data, int *num)
{
	t_list	*new;
	int		ok;
	int		i;

	i = 0;
	while (i < data->num_str)
	{
		new = ft_lstnew(num[i]);
		ok = ft_lstadd_back(&data->start_a, new);
		if (ok == 1)
			ft_exit(data, 0);
		i++;
	}
}
