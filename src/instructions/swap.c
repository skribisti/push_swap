/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:47:13 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 16:58:14 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*swap(t_stack *stack)
{
	t_stack_node	*el;
	t_stack_node	*temp;

	if (stack->size <= 1)
		return (NULL);
	temp = el->next;
	el->next = el;
	return (NULL);
}