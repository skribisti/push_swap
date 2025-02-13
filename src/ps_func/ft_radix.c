/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:01:04 by norabino          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:48 by norabino         ###   ########.fr       */
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
		max /= 2;
		max_bits++;
	}
	return (max_bits);
}

void	ft_radix(t_stack **a, t_stack **b)
{
	printf("%s", "radix");
	rotate(a, 'a');
	reverse_rotate(a, 'a');
	rotate(b, 'a');
	reverse_rotate(b, 'a');
	/*t_stack_node	*el;
	int				size;
	int				max_bits;

	el = (*a)->first;
	size = (*a)->size;
	max_bits = ft_max_bits(*a);
	

	while ((*b)->size)
		push(a, b, 'a');*/
}