/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:16 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_sorted(t_stack *a)
{
	t_stack_node *el;
	int			current;
	int			next;

	if (!a || !a->first)
		return (1);
	el = a->first;
	while (el && el->next)
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

char	**remove_first_arg(char **av)
{
    int 	i;
	char	**new;

	new = malloc(sizeof(char *) * ft_avlen(av));
	if (!new)
		return (NULL);
	i = 0;
    while (av[i])
    {
        new[i] = av[i + 1];
        i++;
    }
	return (new);
}
void	ft_free_new_av(char **new_av, int splitted)
{
	if (splitted)
		ft_free_dst(new_av, ft_avlen(new_av) + 1);
	else 
		free(new_av);
}

int	push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**content_b;
	char	**new_av;
	int		splitted_av;

	a = NULL;
	b = NULL;
	splitted_av = 0;
	if (ac == 1 || (ac == 2 && !av))
		return(1);
	if (ac == 2)
	{
		new_av = ft_split(av[1], ' ');
		splitted_av = 1;
	}
	else
		new_av = remove_first_arg(av);
	if (find_errors(new_av))
		return (ft_free_new_av(new_av, splitted_av), 0);
	a = ft_fill(&a, new_av);
	ft_free_new_av(new_av, splitted_av);
	content_b = ft_split("", ' ');
	b = ft_fill(&b, content_b);
	ft_free_dst(content_b, 0);
	//ft_print_stack(a);
	if (!stack_sorted(a))
	{
		if (a->size <= 5)
			sort_small(&a, &b);
		else
			ft_radix(&a, &b);
	}
	//ft_print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
