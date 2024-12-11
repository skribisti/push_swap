/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:36 by norabino          #+#    #+#             */
/*   Updated: 2024/12/11 19:07:13 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_digits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (sizeof(av[i]) != sizeof(int))
			return (0);
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