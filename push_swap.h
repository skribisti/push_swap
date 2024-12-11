/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2024/12/11 09:44:42 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack_node
{
	int					val;
	int					ind;
	struct s_stack_node *next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	int				size;
}	t_stack;


/* FUNCTIONS */
void	rr_rrotate(t_stack s);
void	r_rotate(t_stack s);
void	p_push(t_stack src, t_stack dst);
void	s_swap(t_stack s);

#endif