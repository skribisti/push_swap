/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2024/12/11 10:01:38 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	cpt;
	t_stack_node	*el;

	el = a->first;
	cpt = 0;
	while (el)
	{
		el = el->next;
		cpt++;
	}
	return (cpt);
}

int	push_swap(void)
{
}

int	main(int ac, char **av)
{
	t_stack	*a; // Init of stacks
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) // Input errors
		return(1); // Error
	if (ac == 2) // String input, call split
		av = split(av[1], ' ');
	if (found_errors(a))
		return (free(a), free(b), NULL); //ERROR
	a = ft_fill(&a, av[1]);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) <= 5)
			sort_five(&a);
		else if (stack_len(a) > 5)
			ft_redix(&a, &b);
	}
	return (0);
}