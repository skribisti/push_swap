/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2024/12/17 14:59:08 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
#include <stdio.h>
//# include "../libft/libft.h"
//# include "../printf/ft_printf.h"

typedef struct s_stack_node
{
	int					val;
	int					ind;
	int					push_cost;
	struct s_stack_node *next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	int				size;
}	t_stack;


/* FUNCTIONS */

// Ft_fill :
int	ft_first_min_val(t_stack *a);
int	ft_min_val(t_stack *a, int prev);
t_stack	*ft_ind(t_stack **a);
t_stack	*ft_fill(t_stack **a, char **av);

int		stack_len(t_stack *a);

// Atoi :
int		ft_atoi(char *nptr);
int		ft_isdigit(int c);

// Errors :
int		find_errors(char **av);
int		find_dup(char **av);
int		only_digits(char **av);

// Ft_split :
char	**ft_split(char *str, char c);
void	ft_build_line(char *str, int *s, int *e, char *c);
int		ft_countwords(char *s, int c);
char	*ft_strndup(char *str, int n);

// Push swap allowed funcs
void	s_swap(t_stack *s, char stack);
void	p_push(t_stack *src, t_stack *dst);
void	r_rotate(t_stack *s, char stack);
void	rr_rrotate(t_stack *s, char stack);

#endif