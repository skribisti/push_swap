/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:40:27 by norabino          #+#    #+#             */
/*   Updated: 2025/01/28 13:34:49 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void *rotate(t_stack **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    if ((*stack)->size < 2)
        return (NULL);
    first = (*stack)->first;
    last = (*stack)->first;
    while (last->next)
        last = last->next;
    (*stack)->first = first->next;
    first->next = NULL;
    last->next = first;
    return (NULL);
}