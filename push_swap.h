/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2024/12/04 09:41:37 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack_node
{
	int		*val;
	int		index;
	int		push_cost;
	int		above_median;
	int		cheapest;
	struct s_stack_node *target;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

// Errors

// Stack init

// Nodes init

// Stack utils

// Commands


// Algos

#endif