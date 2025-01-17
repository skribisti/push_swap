/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:47:13 by norabino          #+#    #+#             */
/*   Updated: 2025/01/17 11:16:30 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*swap(t_stack *stack)
{
	t_stack_node	*el;
	t_stack_node	*temp;

	el = malloc(sizeof(t_stack_node *));
	temp = malloc(sizeof(t_stack_node *));
	if (!el || !temp || stack->size <= 1)
		return (NULL); //Erreur malloc ou pas assez d'elements
	el = stack->first;
	temp->val = el->val; //Val
	el->val = el->next->val;
	el->next->val = temp->val;
	temp->ind = el->ind; //Ind
	el->ind = el->next->ind;
	el->next->ind = temp->ind;
	
	return (NULL);
}