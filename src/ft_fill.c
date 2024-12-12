/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2024/12/12 16:54:04 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_ind(t_stack *a, char *av, int len_a)
{
	t_stack_node	*el;
	t_stack_node	*tmp;
	int				ind;
	int				min;

	tmp = a->first;
	min = el->val;
	ind = 0;
	while (min + 1 < len_a) // a finir
	{
		el = tmp;
		while (el)
		{
			if (el->val < min)
				min = el->val;
			el = el->next;
		}
		el = tmp;
		while (el)
		{
			if (el->val == min)
			{
				el->ind = ind;
				ind++;
			}
			el = el->next;
		}
	}
}

t_stack	*ft_fill(t_stack *a, char *av)
{
	int				len_a;
	int				i;
	t_stack_node	*el;

	len_a = stack_len(a);
	a = ft_ind(a, av, len_a);
	el = a->first;
	i = 1;
	while (i < len_a)
	{
		el->val = av[i];
		el = el->next;
		i++;
	}
	return (a);
}