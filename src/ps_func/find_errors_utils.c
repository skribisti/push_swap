/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:18:31 by norabino          #+#    #+#             */
/*   Updated: 2025/03/02 19:24:14 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

int	ft_iszero(char *str)
{
	if (ft_strlen(str) == 1 && (str[0] == '0' || str[0] == 0))
		return (1);
	return (0);
}

int	only_int(char **av)
{
	int		i;
	long	nb;

	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if ((nb > 2147483647 || nb < -2147483648)
			|| (!nb && !ft_iszero(av[i])))
			return (0);
		i++;
	}
	return (1);
}
