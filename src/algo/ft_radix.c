/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:01:04 by norabino          #+#    #+#             */
/*   Updated: 2025/02/13 12:28:11 by norabino         ###   ########.fr       */
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

void	ft_radix(t_stack **a, t_stack **b)
{
	int				size;
	int				max_bits;
	int				i;
	int				j;

	size = (*a)->size;
	max_bits = ft_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->first->ind >> i) & 1) == 1)
				rotate(a, 'a');
			else
				push(a, b, 'b');
			j++;
		}
		while ((*b)->size != 0)
			push(a, b, 'a');
		i++;
	}
}