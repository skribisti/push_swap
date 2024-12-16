/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2024/12/16 16:01:16 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_first_min_val(t_stack *a)
{
	t_stack_node	*el;
	int				min;

	el = a->first;
	min = el->val;
	while (el)
	{
		if (min < el->val)
			min = el->val;
		el = el->next;
	}
	return (min);
}
int	ft_min_val(t_stack *a, int prev)
{
	t_stack_node	*el;
	int				min;

	el = a->first;
	min = el->val;
	while (el)
	{
		if (min < el->val && prev < el->val)
			min = el->val;
		el = el->next;
	}
	return (min);
}

t_stack	*ft_ind(t_stack **a)
{
	t_stack_node	*el;
	int				min;
	int				prev;
	int				ind;

	el = (*a)->first;
	prev = ft_first_min_val(*a);
	while (el->val != prev)
		el = el->next;
	el->ind = 0;
	ind = 1;
	while (ind < (*a)->size)
	{
		min = ft_min_val(*a, prev);
		el = (*a)->first;
		while (el->val != min)
			el = el->next;
		el->ind = ind;
		ind++;
		prev = min;
	}
	return (*a);
}

t_stack	*ft_fill(t_stack **a, char **av)
{
	int				i;
	t_stack_node	*el;

	el = (*a)->first;
	i = 1;
	while (i < (*a)->size)
	{
		el->val = ft_atoi(av[i]);
		el = el->next;
		i++;
	}
	(*a)->size = stack_len(*a);
	*a = ft_ind(a);
	return (*a);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	t_stack *a;
	t_stack_node *el;
	t_stack_node *el2;
	t_stack_node *el3;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (1);
	a->first = NULL;
	a->size = 3;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el2 = (t_stack_node *)malloc(sizeof(t_stack_node));
	el3 = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!el || !el2 || !el3)
		return (1);

	el->val = 100;	
	el->next = el2;

	el2->val = 50;
	el2->next = el3;

	el3->val = 70;
	el3->next = NULL;
	
	printf("Values :\n");
	printf("%d\n", el->val);
	printf("%d\n", el2->val);
	printf("%d\n", el3->val);

	a = ft_fill(&a, ft_split("100, 50, 70", ' '));

	free(el);
	free(el2);
	free(el3);
	return (0);
}