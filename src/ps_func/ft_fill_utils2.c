/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:52:54 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 16:53:41 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_avlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_first_min_val(t_stack *a)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = a->first;
	min = el->val;
	i = 0;
	while (i < a->size && el)
	{
		if (min > el->val)
			min = el->val;
		el = el->next;
		i++;
	}
	return (min);
}

int	ft_first_max_val(t_stack *a)
{
	t_stack_node	*el;
	int				max;
	int				i;

	el = a->first;
	max = el->val;
	i = 0;
	while (i < a->size && el)
	{
		if (max < el->val)
			max = el->val;
		el = el->next;
		i++;
	}
	return (max);
}

int	ft_min_val(t_stack *a, int prev)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = a->first;
	min = ft_first_max_val(a);
	if (a->size == 1)
		return (min);
	i = 0;
	while (i < a->size && el)
	{
		if (el->val > prev && (el->val <= min))
			min = el->val;
		el = el->next;
		i++;
	}
	return (min);
}
