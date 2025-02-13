/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2025/02/13 09:08:30 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_sorted(t_stack *a)
{
	t_stack_node *el;
	int			current;
	int			next;

	el = a->first;
	while (el->next)
	{
		current = el->val;
		next = el->next->val;
		if (current > next)
			return (0);
		el = el->next;
	}
	return (1);
}
void	free_stack(t_stack *stack)
{
	t_stack_node	*el;
	t_stack_node	*temp;

	if (!stack->size)
	{
		free(stack);
		return ;
	}
	el = stack->first;
	while (el)
	{
		temp = el;
		el = el->next;
		free(temp);
	}
	free(stack);
}
int	ft_print_stack(t_stack *stack)
{
	t_stack_node	*el;

	printf("Stack :\n");
	int	i = 0;
	if (stack->size == 0)
		printf("%s", "Pile vide.\n");
	else
	{
		el = stack->first;
		while (i < stack->size)
		{
			printf("Value : %d\nIndex : %d\n\n", el->val, el->ind);
			i++;
			el = el->next;
		}
	}
	return (0);
}

void remove_first_arg(char **av)
{
    int i;

	i = 0;
    while (av[i])
    {
        av[i] = av[i + 1];
        i++;
    }
}

int	push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av))
		return(printf("%s", "Wrong format."), 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		remove_first_arg(av);
	if (find_errors(av))
		return (0);
	a = ft_fill(&a, av);
	b = ft_fill(&b, ft_split("", ' '));
	//ft_print_stack(a);
	if (!stack_sorted(a))
	{
		if (a->size <= 5)
			sort_small(&a, &b);
		else
			ft_radix(&a, &b);
	}
	//ft_print_stack(a);
	return (0);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}