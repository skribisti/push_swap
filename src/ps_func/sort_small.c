/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:43 by norabino          #+#    #+#             */
/*   Updated: 2025/02/07 11:49:00 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min_ind(t_stack *a, int prev)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = a->first;
	min = ft_itob(a->size - 1);
	if (a->size == 1)
		return (min);
	i = 0;
	while (i < a->size && el)
	{
		if (el->ind > prev && (el->ind <= min))
				min = el->ind;	
		el = el->next;
		i++;
	}
	return (min);
}

int	ft_get_distance(t_stack *a)
{
	t_stack_node	*el;	
	int				min;
	int				distance;

	el = a->first;
	min = ft_min_ind(a, -1);
	distance = 0;
	while (el->ind != min)
	{
		distance++;
		el = el->next;
	}
	return (distance);
}
void	sort_three(t_stack **a)
{
	t_stack_node	*el;
	int				first_min;
	int				second_min;

	if ((*a)->size != 3)
		return ;
	el = (*a)->first;
	first_min = ft_min_ind(*a, -1);
	second_min = ft_min_ind(*a, first_min);
	if (el->ind == first_min)
	{
		if (el->next->next->ind == second_min) // 1 3 2
		{
			swap(a);
			rotate(a);
		}
	}
	else if (el->next->ind == first_min)
	{
		if (el->ind == second_min) // 2 1 3
			swap(a);
		else // 3 1 2
			rotate(a);
	}
	else if (el->next->next->ind == first_min)
	{
		if (el->ind == second_min) // 2 3 1
		{
			reverse_rotate(a);
		}
		else // 3 2 1
		{
			swap(a);
			reverse_rotate(a);
		}
	}
}


void	sort_four(t_stack **a, t_stack **b)
{
	int				distance;

	distance = ft_get_distance(*a);
	if (distance == 1)
		rotate(a);
	else if (distance == 2)
	{
		rotate(a);
		rotate(a);
	}
	else if (distance == 3)
		reverse_rotate(a);
	if (stack_sorted(*a))
		return ;
	push(a, b, 'b');
	sort_three(a);
	push(a, b, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	printf("%s", "sort 5");
	rotate(a);
	reverse_rotate(a);
	rotate(b);
	reverse_rotate(b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = (*a)->size;
	if (size <= 1)
		return ;
	if (size == 2)
		swap(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a,b);
}
