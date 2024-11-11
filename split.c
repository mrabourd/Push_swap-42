/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:47:40 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 15:29:47 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numchar(char *str, int y)
{
	int	j;

	j = 0;
	if (!str)
		return (0);
	while (str[y] && str[y] == ' ')
		y++;
	while (str[y] && str[y] != ' ')
	{
		y++;
		j++;
	}
	return (j);
}

int	ft_numstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

void	ft_strdup(char *str, char *tab, int *y)
{
	int	j;

	j = 0;
	if (!str || !tab)
		return ;
	while (str[*y] && str[*y] == ' ')
		*y += 1;
	while (tab && str[*y] && str[*y] != ' ')
	{
		tab[j] = str[*y];
		j++;
		*y += 1;
		if (str[*y] == '\0' || str[*y] == ' ')
			break ;
	}
	tab[j] = '\0';
}

void	ft_split(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	data->num_str = ft_numstr(data->num_char);
	data->tab = malloc(sizeof(char *) * (data->num_str + 1));
	if (data->tab == NULL)
		ft_exit(data, 0);
	while (i < data->num_str)
	{
		data->tab[i] = malloc(sizeof(char)
				* (ft_numchar(data->num_char, y) + 1));
		if (!data->tab[i])
			ft_exit(data, 0);
		ft_strdup(data->num_char, data->tab[i], &y);
		i++;
		while (data->num_char[y] == ' ')
			y++;
	}
	data->tab[i] = NULL;
}
