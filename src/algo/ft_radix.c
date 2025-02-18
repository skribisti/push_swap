/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:01:04 by norabino          #+#    #+#             */
/*   Updated: 2025/02/18 15:08:51 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_max_bits(t_stack *a)
{
	t_stack_node	*el;
	int				max;
	int				max_bits;

	el = a->first;
	max = el->ind;
	max_bits = 0;
	while (el)
	{
		if (el->ind > max)
			max = el->ind;
		el = el->next;
	}
	while (max)
	{
		max /= 10;
		max_bits++;
	}
	return (max_bits);
}

int	is_one(int ind, int i)
{
	int	max_digits;
	int	nb;
	int	multiplicator;
	int	res;

	max_digits = 0;
	nb = ind;
	while (nb)
	{
		nb /= 10;
		max_digits++;
	}
	if (max_digits < i)
		return (0);
	multiplicator = 1;
	while (i)
	{
		multiplicator *= 10;
		i--;
	}
	res = ind / multiplicator;
	if (res % 10 == 0)
		return(0);
	return (1);
}

void	ft_radix(t_stack **a, t_stack **b)
{
	t_stack_node	*el;
	int				i;
	int				j;
	int				size;
	int				max_bits;

	i = 0;
	el = (*a)->first;
	size = (*a)->size;
	max_bits = ft_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size || (stack_sorted(*a) && !(*b)->size))
		{
			el = (*a)->first;
			if (is_one(el->ind, i))
				rotate(a, 'a');
			else
				push(a, b, 'b');
		}
		while ((*b)->size)
			push(a, b, 'a');
		i++;
	}
}