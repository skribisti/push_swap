/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:36 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 17:18:43 by norabino         ###   ########.fr       */
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
			if (((av[i][j] == '-') && ((j && negative) || j))
			|| (av[i][j] == '-' && !(av[i][j + 1]))
			|| ((!ft_isdigit(av[i][j])) && !(av[i][j] == '-')))
				return (0);
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

int	find_errors(char **av)
{
	if (!only_digits(av)
		|| !find_dup(av)
		|| !only_int(av))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}
