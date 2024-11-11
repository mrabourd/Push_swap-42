/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:00:41 by mrabourd          #+#    #+#             */
/*   Updated: 2023/02/03 17:11:16 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*malloc_z(t_data *data)
{
	char	*s1;

	s1 = malloc(sizeof(char) * 1);
	if (s1 == 0)
		ft_exit(data, 0);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(t_data *data, char *s2)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (data->num_char == 0)
		data->num_char = malloc_z(data);
	dst = malloc((ft_len(data->num_char) + ft_len(s2) + 2) * sizeof(char));
	if (dst == 0 || !s2 || ft_empty(s2) == 1)
	{
		free (dst);
		ft_exit(data, 0);
	}
	while (data->num_char[i] != '\0')
	{
		dst[i] = data->num_char[i];
		i++;
	}
	free (data->num_char);
	dst[i++] = ' ';
	while (s2[y] != '\0')
		dst[i++] = s2[y++];
	dst[i] = '\0';
	return (dst);
}

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
		{
			if (str[i] == ' ' && str[i + 1] == '\0')
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		if (str[i] != ' ')
			break ;
	}
	return (0);
}

int	ft_minus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] > '9'
				|| s[i + 1] == '\0'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (s[i] == '+' && (s[i + 1] < '0' || s[i + 1] > '9'
				|| s[i + 1] == '\0'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *num, t_data *data)
{
	int		i;
	long	res;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	if (!data->tab)
		ft_exit(data, 0);
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			signe = -signe;
		if (ft_minus(num) == 1 || ft_empty(num) == 1)
			ft_exit(data, 0);
		i++;
	}
	while (num[i])
	{
		res = (res * 10) + num[i] - 48;
		i++;
	}
	if ((signe * res) > 2147483647 || (signe * res) < -2147483648)
		ft_exit(data, 1);
	return (signe * res);
}
