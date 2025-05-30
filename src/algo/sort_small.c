/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:43 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 14:59:14 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_handler(t_stack **a, int ind, int second_min, int pos)
{
	if (pos == 2)
	{
		if (ind == second_min)
			swap(a, 'a');
		else
			rotate(a, 'a');
	}
	else if (pos == 3)
	{
		if (ind == second_min)
			reverse_rotate(a, 'a');
		else
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
	}
}

void	sort_three(t_stack **a, int init_size)
{
	t_stack_node	*el;
	int				first_min;
	int				second_min;

	if ((*a)->size != 3 || stack_sorted(*a))
		return ;
	el = (*a)->first;
	first_min = ft_min_ind(*a, -1, init_size);
	second_min = ft_min_ind(*a, first_min, init_size);
	if (el->ind == first_min)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (el->next->ind == first_min)
		ft_handler(a, el->ind, second_min, 2);
	else if (el->next->next->ind == first_min)
		ft_handler(a, el->ind, second_min, 3);
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
		sort_five(a, b, initial_size);
}
