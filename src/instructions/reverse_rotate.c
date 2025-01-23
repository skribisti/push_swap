/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:54:58 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 01:07:52 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*reverse_rotate(t_stack **stack)
{
	t_stack_node	*el;
	t_stack_node	*temp;

	if ((*stack)->size < 2)
		return (NULL);
	el = malloc(sizeof(t_stack_node *));
	temp = malloc(sizeof(t_stack_node *));
	if (!el || !temp)
		return (NULL);
	el = (*stack)->first;
	while (el)
	{
		if (!(el->next->next))
		{
			el->next = NULL;
			break;
		}
		el = el->next;
	}
	(*stack)->first->val = el->val;
	ft_recalc_ind(stack);
	free(el);
	free(temp);
	return (NULL);
}