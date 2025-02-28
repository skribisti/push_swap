/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:04:41 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 17:16:45 by norabino         ###   ########.fr       */
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
