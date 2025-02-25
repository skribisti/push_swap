/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:52:36 by norabino          #+#    #+#             */
/*   Updated: 2025/02/25 18:01:21 by norabino         ###   ########.fr       */
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
			|| (av[i][j] =='-' && !(av[i][j + 1]))
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

void *ft_atoi_int(char *str)
{
    long res;
    int sign;
    int i;

    res = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    if (!ft_isdigit((unsigned char)str[i]))
        return (NULL);
    while (ft_isdigit((unsigned char)str[i]))
    {
        int digit = str[i] - '0';
        if (((sign == 1) && (res > (INT_MAX - digit) / 10))
		|| ((sign == -1) && (-res < ((long)INT_MIN - digit) / 10)))
            return (NULL); // Overflow
        res = res * 10 + digit;
        i++;
    }
    return (void *)(sign * res);
}

int		ft_iszero(char *str)
{
	if (ft_strlen(str) == 1 && (str[0] == '0' || str[0] == 0))
		return (1);
	return (0);
}

int	only_int(char **av)
{
	int		i;
	void	*nb;

	i = 0;
	while (av[i])
	{
		nb = ft_atoi_int(av[i]);
		if (!nb && !ft_iszero(av[i]) && av[i])
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
	{
		write(2, "Error\n", 7);
		return (1);
	}
	return (0);
}