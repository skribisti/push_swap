/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2025/02/25 17:49:09 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
#define INT_MIN (-2147483648)

typedef struct s_stack_node
{
	int					val;
	int					ind;
	int					push_cost;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	int				size;
}	t_stack;

/* FUNCTIONS */

// Sorting algo :
void	sort_small(t_stack **a, t_stack **b);
void	ft_radix(t_stack **a, t_stack **b);
int		stack_sorted(t_stack *a);

// Ft_fill :
int		ft_avlen(char **av);
int		ft_first_min_val(t_stack *a);
int		ft_min_val(t_stack *a, int prev);
t_stack	*ft_ind(t_stack **a);
t_stack	*ft_fill(t_stack **a, char **av);
t_stack	*ft_recalc_ind(t_stack **stack);
int		ft_itob(int nb);

// Push_swap
int	push_swap(int ac, char **av);
int		ft_strlen(char *str);
int		stack_len(t_stack *a);
void	free_stack(t_stack *stack);

// Atoi :
int		ft_atoi(char *nptr);
int		ft_isdigit(int c);

// Errors :
int		find_errors(char **av);
int		find_dup(char **av);
int		only_digits(char **av);

// Ft_split :
char	*ft_strndup(char *str, int n);
int		ft_countwords(char *s, int c);
void	ft_build_line(char *str, int *s, int *e, char *c);
void	ft_free_dst(char **dst, int i);
char	**ft_split(char *str, char c);

// Push swap allowed funcs
void	swap(t_stack **stack, char to_s);
void	push(t_stack **a, t_stack **b, char push_to);
void	rotate(t_stack **stack, char to_r);
void	reverse_rotate(t_stack **stack, char to_rr);

#endif