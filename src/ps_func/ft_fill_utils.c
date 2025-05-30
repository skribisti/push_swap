/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:55 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 17:07:02 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int		res;
	int		sign;
	int		i;
	char	*str;

	str = (char *)nptr;
	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	stack_len(t_stack *a)
{
	t_stack_node	*el;
	int				cpt;

	el = a->first;
	cpt = 0;
	while (el)
	{
		el = el->next;
		cpt++;
	}
	free(el);
	return (cpt);
}

int	ft_itob(int nb)
{
	int	bin;
	int	place;

	bin = 0;
	place = 1;
	while (nb > 0)
	{
		bin += (nb % 2) * place;
		nb /= 2;
		place *= 10;
	}
	return (bin);
}
