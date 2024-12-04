/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2024/12/04 09:58:54 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	cpt;

	cpt = 0;
	while (a)
	{
		a = a->next;
		cpt++;
	}
	return (a);
}

int	push_swap(void)
{
}

int	main(int ac, char **av)
{
	t_stack_node	*a; // Init of stacks
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) // Input errors
		return(1); // Error
	if (ac == 2) // String input, call split
		av = split(av[1], ' ');
	init_stack(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		if (stack_len(a) == 3)
			sort_three(&a);;
		if (stack_len(a) > 3)
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}