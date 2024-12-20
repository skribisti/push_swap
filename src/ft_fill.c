/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2024/12/20 15:56:24 by norabino         ###   ########.fr       */
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
	char *base;
	int	res;

	if (nb == 0)
		return (0);
	base = "01";
	res = 0;
	if (nb > ft_strlen(base))
		ft_itob(nb / ft_strlen(base));
	res = res + nb % ft_strlen(base);
	return (res);
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
	//*a = ft_bin_ind(a);
	return (*a);
}

int main()
{
	t_stack *a;
	t_stack_node *el;
	char **av;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (1);
	a->first = NULL;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!el)
		return (printf("erreur malloc"), 1);
	el = a->first;
	av = ft_split("1 2 3 4 5 6", ' ');
	if (!av) 
    	return (printf("Error: ft_split failed\n"), 1);
	a->size = ft_avlen(av);
	a = ft_fill(&a, av);

	printf("Stack:\n\n");
	int	i = 0;
	while (i < a->size)
	{
		printf("Value : %d;\nIndex : %d\n\n", a->first->val, a->first->ind);
		i++;
		a->first = a->first->next;
	}
	
	free(el);
	return (0);
}