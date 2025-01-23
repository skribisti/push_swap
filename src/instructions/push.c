/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:24 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 15:46:18 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*push(t_stack **a, t_stack **b, char push_to)
{
	t_stack_node	*to_push;
	t_stack_node	*temp;

	to_push = malloc(sizeof(t_stack_node *));
	temp = malloc(sizeof(t_stack_node *));
	if (push_to == 'a')
	{
		if (!(*b)->size)
			return (NULL);
		to_push = (*b)->first;
		(*b)->first = (*b)->first->next;
		temp = (*a)->first;
		(*a)->first = to_push;
		to_push->next = temp;
		(*b)->size -= 1;
		(*a)->size += 1;
	}
	if (push_to == 'b')
	{
		if (!(*a)->size)
			return (NULL);
		to_push = (*a)->first;
		(*a)->first = (*a)->first->next;
		temp = (*b)->first;
		(*b)->first = to_push;
		to_push->next = temp;
		(*a)->size -= 1;
		(*b)->size += 1;
	}
	return (NULL);
}