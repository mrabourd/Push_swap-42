/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:08:16 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 15:32:01 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freeall(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		exit(EXIT_FAILURE);
	if (tab[i])
	{
		while (tab[i])
		{
			free (tab[i]);
			i++;
		}
	}
	free (tab);
}

void	ft_exit(t_data *data, int i)
{
	if (i == 1)
		write (2, "Error\n", 6);
	if (data->start_a && data->start_a != NULL)
		ft_lstclear(&data->start_a);
	if (data->start_b && data->start_b != NULL)
		ft_lstclear(&data->start_b);
	if (data->tab)
		ft_freeall(data->tab);
	if (data->num_i)
		free (data->num_i);
	if (data->num_char)
		free (data->num_char);
	exit (EXIT_SUCCESS);
}
