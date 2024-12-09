/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2024/12/11 19:13:02 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill(t_stack *a, char *av)
{
	int				len_a;
	int				i;
	t_stack_node	*el;

	len_a = stack_len(a);
	el = a->first;
	el->ind = 0;
	i = 1;
	while (i < len_a)
	{
		el->val = av[i];
		el->ind = i;
		el = el->next;
		i++;
	}
}