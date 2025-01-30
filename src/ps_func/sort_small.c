/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:43 by norabino          #+#    #+#             */
/*   Updated: 2025/01/30 22:01:52 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	swap(b);
	size = (*a)->size;
	if (size < 2)
		return ;
	if (size == 2)
		swap(a);
	else if (size == 3)
		printf("%s", "three");
		//sort_three(a);
	else if (size == 4)
		printf("%s", "four");
		//sort_four(a, b);
	else if (size == 5)
		printf("%s", "five");
		//sort_five(a,b);
}
