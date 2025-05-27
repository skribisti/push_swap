/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2025/03/17 11:50:48 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (!stack_sorted(a))
	{
		if (a->size <= 5)
			sort_small(&a, &b);
		else
			ft_radix(&a, &b);
	}
	free_stack(a);
	free_stack(b);
}

char	**ft_build_new_av(int ac, char **av)
{
	char	**new;

	if (ac == 2)
		new = ft_split(av[1], ' ');
	else
		new = remove_first_arg(av);
	return (new);
}

void	ft_full_fill_and_sort(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**content_b;
	char	**new_av;
	int		splitted;

	a = NULL;
	b = NULL;
	splitted = 0;
	new_av = ft_build_new_av(ac, av);
	if (ac == 2)
		splitted = 1;
	if (find_errors(new_av))
	{
		ft_free_new_av(new_av, splitted);
		return ;
	}
	a = ft_fill(&a, new_av);
	ft_free_new_av(new_av, splitted);
	content_b = ft_split("", ' ');
	b = ft_fill(&b, content_b);
	ft_free_dst(content_b, 0);
	ft_sort(a, b);
}

int	push_swap(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av))
		return (1);
	if (ac == 2 && (av[1][0] == ' ' || !av[1][0]))
		return (write(2, "Error\n", 7), 1);
	ft_full_fill_and_sort(ac, av);
	return (0);
}
