/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:43 by norabino          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:37 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min_ind(t_stack *a, int prev, int init_size)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = a->first;
	min = ft_itob(init_size - 1);
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

int	ft_get_distance(t_stack *a, int init_size)
{
	t_stack_node	*el;	
	int				min;
	int				distance;

	el = a->first;
	min = ft_min_ind(a, -1, init_size);
	distance = 0;
	while (el->ind != min)
	{
		distance++;
		el = el->next;
	}
	return (distance);
}
void	sort_three(t_stack **a, int init_size)
{
	t_stack_node	*el;
	int				first_min;
	int				second_min;

	if ((*a)->size != 3)
		return ;
	el = (*a)->first;
	first_min = ft_min_ind(*a, -1, init_size);
	second_min = ft_min_ind(*a, first_min, init_size);
	if (el->ind == first_min)
	{
		if (el->next->next->ind == second_min) // 1 3 2
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
	}
	else if (el->next->ind == first_min)
	{
		if (el->ind == second_min) // 2 1 3
			swap(a, 'a');
		else // 3 1 2
			rotate(a, 'a');
	}
	else if (el->next->next->ind == first_min)
	{
		if (el->ind == second_min) // 2 3 1
		{
			reverse_rotate(a, 'a');
		}
		else // 3 2 1
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
	}
}


void	sort_four(t_stack **a, t_stack **b, int init_size)
{
	int				distance;

	if ((*a)->size != 4)
		return ;
	distance = ft_get_distance(*a, init_size);
	if (distance == 1)
		rotate(a, 'a');
	else if (distance == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
	}
	else if (distance == 3)
		reverse_rotate(a, 'a');
	if (stack_sorted(*a))
		return ;
	push(a, b, 'b');
	sort_three(a, init_size);
	push(a, b, 'a');
}

void	sort_five(t_stack **a, t_stack **b, int init_size)
{
	int				distance;

	if ((*a)->size != 5)
		return ;
	distance = ft_get_distance(*a, init_size);
	if (distance == 1)
		rotate(a, 'a');
	else if (distance == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
	}
	else if (distance == 3)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (distance == 4)
		reverse_rotate(a, 'a');
	if (stack_sorted(*a))
		return ;
	push(a, b, 'b');
	sort_four(a, b, init_size);
	push(a, b, 'a');
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	initial_size;

	initial_size = (*a)->size;
	if (initial_size <= 1)
		return ;
	if (initial_size == 2)
		swap(a, 'a');
	else if (initial_size == 3)
		sort_three(a, initial_size);
	else if (initial_size == 4)
		sort_four(a, b, initial_size);
	else if (initial_size == 5)
		sort_five(a,b, initial_size);
}
