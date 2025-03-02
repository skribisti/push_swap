/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2025/03/02 19:44:04 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

t_stack	*ft_bin_ind(t_stack **a)
{
	t_stack_node	*el;
	int				i;

	el = (*a)->first;
	i = 0;
	while (i < (*a)->size)
	{
		el->ind = ft_itob(el->ind);
		el = el->next;
		i++;
	}
	return (*a);
}

t_stack	**ft_fill_elems(t_stack **stack, char **av)
{
	t_stack_node	*el;
	int				i;

	(*stack)->first = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!(*stack)->first)
		return (NULL);
	el = (*stack)->first;
	i = 0;
	while (i < ft_avlen(av))
	{
		if (!av[i])
			return (NULL);
		el->val = ft_atoi(av[i]);
		el->ind = 0;
		if (i != ft_avlen(av) - 1)
		{
			el->next = (t_stack_node *)malloc(sizeof(t_stack_node));
			if (!el->next)
				return (free_stack(*stack), NULL);
			el = el->next;
		}
		i++;
	}
	el->next = NULL;
	return (stack);
}

int	ft_check_av(t_stack **stack, char **av)
{
	(*stack) = malloc(sizeof(t_stack));
	if (!(*stack) || !av)
		return (free_stack(*stack), -1);
	if (!ft_avlen(av))
	{
		(*stack)->first = NULL;
		(*stack)->size = 0;
		return (0);
	}
	return (1);
}

t_stack	*ft_fill(t_stack **stack, char **av)
{
	int	check_av;

	check_av = ft_check_av(stack, av);
	if (check_av == -1)
		return (NULL);
	if (check_av == 0)
		return (*stack);
	stack = ft_fill_elems(stack, av);
	if (!stack)
		return (NULL);
	(*stack)->size = stack_len(*stack);
	*stack = ft_ind(stack);
	*stack = ft_bin_ind(stack);
	return (*stack);
}
