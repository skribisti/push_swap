/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:55:46 by norabino          #+#    #+#             */
/*   Updated: 2024/12/04 10:05:42 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_err(av[i]))
			free_errors(a);
		n = ft_atoi(av[i]);
		if (check_limits(n))
			free_errors(a);
		if (dup_errors(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
