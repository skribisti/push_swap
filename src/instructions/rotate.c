/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:40:27 by norabino          #+#    #+#             */
/*   Updated: 2025/01/21 01:04:07 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*rotate(t_stack **stack)
{
	t_stack_node	*el;
	t_stack_node	*temp;

	el = malloc(sizeof(t_stack_node *));
	temp = malloc(sizeof(t_stack_node *));
	if (!el || !temp)
		return (NULL);
	el = (*stack)->first;
	temp->val = el->val;
	while (el)
	{
		el->val = el->next->val;
		el = el->next;
	}
	el->next->val = temp->val;
	ft_recalc_ind(stack);
	return (NULL);
}