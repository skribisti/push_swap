/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:54:58 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 10:00:06 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "../../includes/push_swap.h"

void *reverse_rotate(t_stack **stack)
{
    t_stack_node *last;
    t_stack_node *prev;

    if ((*stack)->size < 2)
        return (NULL);
    last = (*stack)->first;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = (*stack)->first;
    (*stack)->first = last;
    return (NULL);
}
