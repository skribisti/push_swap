/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:40:27 by norabino          #+#    #+#             */
/*   Updated: 2025/01/22 10:50:24 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*rotate(t_stack **stack)
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
	temp->val = el->val;
	while (el->next)
	{
		el->val = el->next->val;
		el = el->next;
	}
	el->val = temp->val;
	ft_recalc_ind(stack);
	return (NULL);
}