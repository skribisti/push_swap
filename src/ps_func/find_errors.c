/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:36 by norabino          #+#    #+#             */
/*   Updated: 2025/02/13 09:22:36 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	only_digits(char **av)
{
	int	i;
	int	j;
	int	negative;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		negative = 0;
		if ((av[i][0]) == '-')
			negative = 1;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j && negative)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_dup(char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void *ft_atoi_int(char *str)
{
	int		res;
	int		sign;
	int		i;
	int		next;

	i = 0;
	sign = 1;
	res = 0;
	next = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		next = res * 10 + str[i] - '0';
		if (next > 2147483647 || next <= -2147483648)
			return (NULL);
		res = next;
		i++;
	}
	return (res * sign);
}

int	only_int(char **av)
{
	int	i;
	int	nb;

	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb >= 2147483647 || nb <= -2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	find_errors(char **av)
{
	if (!only_digits(av) 
	|| !find_dup(av)
	|| !only_int(av))
		return (printf("%s", "Error\n"), 1);
	return (0);
}