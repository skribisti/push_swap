/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:47:13 by norabino          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:37 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack, char to_s)
{
	t_stack_node	*second;
	t_stack_node	*first;

	if (!(*stack))
		return ;
	second = (*stack)->first;
	first = second->next;
	(*stack)->first = first;
	second->next = second->next->next;
	first->next = second;
	if (to_s == 'a')
		write(1, "sa\n", 3);
	if (to_s == 'b')
		write(1, "sb\n", 3);
}