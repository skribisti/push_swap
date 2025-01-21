/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2025/01/21 01:10:50 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_avlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_first_min_val(t_stack *a)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = a->first;
	min = el->val;
	i = 0;
	while (i < a->size && el)
	{
		if (min > el->val)
			min = el->val;
		el = el->next;
		i++;
	}
	return (min);
}

int	ft_first_max_val(t_stack *a)
{
	t_stack_node	*el;
	int				max;
	int				i;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = a->first;
	max = el->val;
	i = 0;
	while (i < a->size && el)
	{
		if (max < el->val)
			max = el->val;
		el = el->next;
		i++;
	}
	return (max);
}
int	ft_min_val(t_stack *a, int prev)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = a->first;
	min = ft_first_max_val(a);
	if (a->size == 1)
		return (min);
	i = 0;
	while (i < a->size && el)
	{
		if (el->val > prev && (el->val <= min))
				min = el->val;	
		el = el->next;
		i++;
	}
	return (min);
}

int	ft_itob(int nb)
{
    int	bin;
    int	place;

    if (nb == 0)
        return (0);
    bin = 0;
    place = 1;
    while (nb > 0)
    {
        bin += (nb % 2) * place;
        nb /= 2;
        place *= 10;
    }
    return (bin);
}

t_stack	*ft_ind(t_stack **a)
{
	t_stack_node	*el;
	int				min;
	int				prev;
	int				ind;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = (*a)->first;
	prev = ft_first_min_val(*a);
	while (el->val != prev)
		el = el->next;
	el->ind = 0;
	ind = 1;
	while (ind < (*a)->size)
	{
		min = ft_min_val(*a, prev);
		el = (*a)->first;
		while (el->val != min)
			el = el->next;
		el->ind = ind;
		ind++;
		prev = min;
	}
	return (*a);
}
t_stack	*ft_bin_ind(t_stack **a)
{
	t_stack_node	*el;
	int				i;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = (*a)->first;
	i = 0;
	while (i < (*a)->size)
	{
		el->ind = ft_itob(el->ind);
		el = el->next;
		i++;
	}
	return (*a);
}


t_stack	*ft_fill(t_stack **a, char **av)
{
	int				i;
	t_stack_node	*el = NULL;

	if (!(*a) || !av)
        return (NULL);
	(*a)->first = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = (*a)->first;
	i = 0;
	while (i < (*a)->size)
	{
		el->val = ft_atoi(av[i]);
		el->next = (t_stack_node *)malloc(sizeof(t_stack_node));
		el = el->next;
		i++;
	}
	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = NULL;
	(*a)->size = stack_len(*a) - 1;
	*a = ft_ind(a);
	*a = ft_bin_ind(a);
	return (*a);
}

t_stack *ft_recalc_ind(t_stack **stack)
{
	*stack = ft_ind(stack);
	*stack = ft_bin_ind(stack);
	return (*stack);
}

int main()
{
	t_stack *a;
	t_stack *b;
	t_stack_node *el_a;
	t_stack_node *el_b;
	char **content_a;
	char **content_b;

	a = (t_stack *)malloc(sizeof(t_stack *));
	b = (t_stack *)malloc(sizeof(t_stack *));
	if (!a || !_BITS_STDIO_LIM_H)
		return (1);
	a->first = NULL;
	b->first = NULL;

	el_a = (t_stack_node *)malloc(sizeof(t_stack_node *));
	el_b = (t_stack_node *)malloc(sizeof(t_stack_node *));
	if (!el_a || !el_b)
		return (printf("Erreur malloc"), 1);
	el_a = a->first;
	el_b = b->first;
	content_a = ft_split("1 2 3", ' '); 
	content_b = ft_split("4 5 6", ' ');
	if (!content_a || !content_b) 
    	return (printf("Error: ft_split failed\n"), 1);
	a->size = ft_avlen(content_a);
	b->size = ft_avlen(content_b);
	a = ft_fill(&a, content_a);
	b = ft_fill(&b, content_b);

	//push(&a, &b, 'b');
	rotate(&a);

	printf("StackA:\n");
	int	i = 0;
	while (i < a->size)
	{
		printf("Value : %d;\nIndex : %d\n\n", a->first->val, a->first->ind);
		i++;
		a->first = a->first->next;
	}
	i = 0;
	printf("\n”StackB:\n");
	while (i < b->size)
	{
		printf("Value : %d;\nIndex : %d\n\n", b->first->val, b->first->ind);
		i++;
		b->first = b->first->next;
	}
	free(el_a);
	free(el_b);
	return (0);
}