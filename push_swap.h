/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2024/12/11 19:08:53 by norabino         ###   ########.fr       */
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

// Errors :
int	find_errors(char **av);
int	find_dup(char **av);
int	only_digits(char **av);

// Ft_split :
char	**ft_split(char const *str, char c);
void	ft_build_line(char *str, int *s, int *e, char *c);
int	ft_countwords(char const *s, int c);
char	*ft_strndup(char *str, int n);

// Fill stack
t_stack	*ft_fill(t_stack *a, char *av);

// Push swap allowed funcs
void	s_swap(t_stack *s);
void	p_push(t_stack *src, t_stack *dst);
void	r_rotate(t_stack *s);
void	rr_rrotate(t_stack *s);

#endif