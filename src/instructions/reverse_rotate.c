/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:54:58 by norabino          #+#    #+#             */
/*   Updated: 2025/02/21 17:44:05 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "../../includes/push_swap.h"

void reverse_rotate(t_stack **stack, char to_rr)
{
    t_stack_node *last;
    t_stack_node *prev;

    if ((*stack)->size < 2)
        return ;
    last = (*stack)->first;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = (*stack)->first;
    (*stack)->first = last;
    if (to_rr == 'a')
        write(1, "rra\n", 4);
    if (to_rr == 'b')
       write(1, "rrb\n", 4);
}
