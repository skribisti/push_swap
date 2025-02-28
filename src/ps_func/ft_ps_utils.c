/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:37:09 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 16:01:19 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_sorted(t_stack *a)
{
	t_stack_node	*el;
	int				current;
	int				next;

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

char	**remove_first_arg(char **av)
{
	int		i;
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
