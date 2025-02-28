/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 17:19:54 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					val;
	int					ind;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*first;
	int				size;
}	t_stack;

/* FUNCTIONS */

// Sorting algo :
void	ft_radix(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);
int		stack_sorted(t_stack *a);
int		ft_min_ind(t_stack *a, int prev, int init_size);
int		ft_get_distance(t_stack *a, int init_size);
void	ft_handler(t_stack **a, int ind, int second_min, int pos);
void	sort_three(t_stack **a, int init_size);
void	sort_four(t_stack **a, t_stack **b, int init_size);
void	sort_five(t_stack **a, t_stack **b, int init_size);

// Ft_fill :
int		ft_avlen(char **av);
int		ft_first_min_val(t_stack *a);
int		ft_min_val(t_stack *a, int prev);
t_stack	*ft_ind(t_stack **a);
t_stack	*ft_fill(t_stack **a, char **av);
t_stack	*ft_recalc_ind(t_stack **stack);
int		ft_itob(int nb);

// Push_swap
int		push_swap(int ac, char **av);
int		ft_strlen(char *str);
int		stack_len(t_stack *a);
void	free_stack(t_stack *stack);
void	ft_free_new_av(char **new_av, int splitted);
char	**remove_first_arg(char **av);

// Atoi :
int		ft_atoi(char *nptr);
int		ft_isdigit(int c);

// Errors :
int		find_errors(char **av);
int		find_dup(char **av);
int		only_digits(char **av);
int		only_int(char **av);

// Ft_split :
char	*ft_strndup(char *str, int n);
int		ft_countwords(char *s, int c);
void	ft_build_line(char *str, int *s, int *e, char *c);
void	ft_free_dst(char **dst, int i);
char	**ft_split(char *str, char c);
void	ft_init_to_null(char **dst, int words);

// Push swap allowed funcs
void	swap(t_stack **stack, char to_s);
void	push(t_stack **a, t_stack **b, char push_to);
void	rotate(t_stack **stack, char to_r);
void	reverse_rotate(t_stack **stack, char to_rr);

#endif