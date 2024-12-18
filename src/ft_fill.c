/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2024/12/18 11:16:09 by norabino         ###   ########.fr       */
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

char	*ft_strndup(char *str, int n)
{
	char	*tab;
	int		i;

	tab = (char *)malloc(n + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	ft_countwords(char *s, int c)
{
	int	i;
	int	j;
	int	in;

	i = 0;
	j = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] != (char)c && in != 1)
		{
			in = 1;
			j++;
		}
		if (s[i] == (char)c && in == 1)
			in = 0;
		i++;
	}
	return (j);
}

void	ft_build_line(char *str, int *s, int *e, char *c)
{
	while (str[*s] == *c && str[*s])
		(*s)++;
	*e = *s;
	while (str[*e] != *c && str[*e])
		(*e)++;
}

void	ft_free_dst(char ***dst, int *i)
{
	while ((*i)--)
		free(*dst[*i]);
	free(*dst);
}

char	**ft_split(char *str, char c)
{
	int		tab[3];
	char	**dst;

	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_countwords(str, (int)c) + 1));
	if (!dst)
		return (NULL);
	tab[2] = 0;
	tab[0] = 0;
	while (str[tab[0]] && tab[2] < ft_countwords(str, (int)c))
	{
		ft_build_line((char *)str, &tab[0], &tab[1], &c);
		dst[tab[2]] = ft_strndup((char *)str + tab[0], tab[1] - tab[0]);
		if (dst[tab[2]] == NULL)
		{
			ft_free_dst(&dst, &tab[2]);
			return (NULL);
		}
		tab[0] = tab[1];
		tab[2]++;
	}
	dst[tab[2]] = 0;
	return (dst);
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
int	ft_min_val(t_stack *a, int prev)
{
	t_stack_node	*el;
	int				min;
	int				i;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	el = a->first;
	min = el->val;
	if (a->size == 1)
		return (min);
	i = 0;
	while (i < a->size && el)
	{
		if (el->val <= prev)
		{
			i++;
			el = el->next;
		}
		else
		{
		min = prev - 1;
		if (el->val < min)
			min = el->val;
		el = el->next;
		i++;
		}
	}
	return (min);
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
	el = NULL;
	(*a)->size = stack_len(*a) - 1;
	*a = ft_ind(a);
	return (*a);
}

#include <stdlib.h>
int main()
{
	t_stack *a;
	t_stack_node *el;
	t_stack_node *el2;
	t_stack_node *el3;
	char **av;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (1);
	a->first = NULL;

	el = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!el)
		return (printf("erreur malloc"), 1);
	el = a->first;
	av = ft_split("100 200", ' ');
	if (!av)
    	return (printf("Error: ft_split failed\n"), 1);
	a->size = ft_avlen(av);
	a = ft_fill(&a, av);

	printf("Values Stack:\n");
	printf("%d; %d\n", a->first->val, a->first->ind);
	printf("%d; %d\n", a->first->next->val, a->first->next->ind);
	//printf("%d; %d\n", a->first->next->next->val, a->first->next->next->ind);

	free(el);
	return (0);
}