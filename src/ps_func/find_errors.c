/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:36 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 15:33:17 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	only_digits(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' && av[i][j] > '9') 
				|| av[i][0] == '+' || av[i][0] == '-')
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

	i = 1;
	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[i])
		{
			if (av[i] == av[j])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	find_errors(char **av)
{
	if (!only_digits(av) 
	&& !find_dup(av))
		return (0);
	return (1);
}