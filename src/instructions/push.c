/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:24 by norabino          #+#    #+#             */
/*   Updated: 2025/02/21 17:43:10 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack_node	*to_push;
	t_stack_node	*temp;

	if (!(*b)->size)
			return ;
	to_push = (*b)->first;
	(*b)->first = (*b)->first->next;
	temp = (*a)->first;
	(*a)->first = to_push;
	to_push->next = temp;
	(*b)->size -= 1;
	(*a)->size += 1;
	write(1, "pa\n", 3);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack_node	*to_push;
	t_stack_node	*temp;

	if (!(*a)->size)
			return ;
	to_push = (*a)->first;
	(*a)->first = (*a)->first->next;
	temp = (*b)->first;
	(*b)->first = to_push;
	to_push->next = temp;
	(*a)->size -= 1;
	(*b)->size += 1;
	write(1, "pb\n", 3);;
}

void	push(t_stack **a, t_stack **b, char push_to)
{
	if (push_to == 'a')
		push_to_a(a,b);
	if (push_to == 'b')
		push_to_b(a,b);
}