/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:40:27 by norabino          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:20 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate(t_stack **stack, char to_r)
{
    t_stack_node *first;
    t_stack_node *last;

    if ((*stack)->size < 2)
        return ;
    first = (*stack)->first;
    last = (*stack)->first;
    while (last->next)
        last = last->next;
    (*stack)->first = first->next;
    first->next = NULL;
    last->next = first;
    if (to_r == 'a')
		write(1, "ra\n", 3);
	if (to_r == 'b')
		write(1, "rb\n", 3);
}