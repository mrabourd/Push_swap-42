/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:09:52 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 17:10:51 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_notdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+' && str[i] != ' ')
			return (1);
		if ((str[i] >= '0' && str[i] <= '9')
			&& (str[i + 1] == '+' || str[i + 1] == '-'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		n--;
		str++;
	}
}

int	ft_parse(char **str, int ac, t_data *data)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		data->num_char = ft_strjoin(data, str[i]);
		i++;
	}
	ft_split(data);
	data->num_i = malloc(sizeof(int) * data->num_str);
	if (!data->num_i || data->num_str == 0)
		ft_exit(data, 1);
	i = 0;
	while (i < data->num_str)
	{
		data->num_i[i] = ft_atoi(data->tab[i], data);
		i++;
	}
	check_dup(data);
	create_list(data, data->num_i);
	assign_value(&data->start_a);
	if (ft_already_sorted(data) == 0)
		ft_sort(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	ft_bzero(&data, sizeof(data));
	i = 1;
	if (argc < 2)
		return (0);
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (ft_len(argv[i]) == 0)
				ft_exit (&data, 1);
			if (ft_notdigit(argv[i]) == 1)
				ft_exit (&data, 1);
			i++;
		}
		ft_parse(argv, argc, &data);
	}
	ft_exit(&data, 0);
	return (0);
}
