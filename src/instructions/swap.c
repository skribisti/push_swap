/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:47:13 by norabino          #+#    #+#             */
/*   Updated: 2025/01/27 13:35:43 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*swap(t_stack **stack)
{
	t_stack_node	*second;
	t_stack_node	*first;

	first = malloc(sizeof(t_stack_node *));
	second = malloc(sizeof(t_stack_node *));
	if (!first || !second || (*stack)->size <= 1)
		return (NULL);
	second = (*stack)->first;
	first = second->next;
	(*stack)->first = first;
	second->next = second->next->next;
	first->next = second;
	return (NULL);
}