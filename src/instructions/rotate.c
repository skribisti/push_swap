/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:40:27 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 15:52:51 by norabino         ###   ########.fr       */
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
	temp = el;
	while (el->next)
	{
		el = el->next;
		el = el->next;
	}
	el = temp;
	return (NULL);
}