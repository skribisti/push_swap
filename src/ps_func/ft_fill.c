/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:05 by norabino          #+#    #+#             */
/*   Updated: 2025/01/28 13:42:24 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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


t_stack	*ft_fill(t_stack **stack, char **av)
{
	int				i;
	t_stack_node	*el = NULL;

	if (!(*stack) || !av || !ft_avlen(av))
        return (NULL);
	(*stack)->first = (t_stack_node *)malloc(sizeof(t_stack_node *));
	el = (*stack)->first;
	i = 0;
	while (i < (*stack)->size)
	{
		el->val = ft_atoi(av[i]);
		if (i != (*stack)->size - 1)
		{
			el->next = (t_stack_node *)malloc(sizeof(t_stack_node *));
			el = el->next;
		}
		i++;
	}
	el->next = NULL;
	(*stack)->size = stack_len(*stack);
	*stack = ft_ind(stack);
	*stack = ft_bin_ind(stack);
	return (*stack);
}

/*
void	verif_instruction(char *instruc, t_stack **a, t_stack **b)
{
	if (instruc[0] == 's' && instruc[1] == 'a')
		swap(&a);
	if (instruc[0] == 's' && instruc[1] == 'b')
		swap(&b);
	if (instruc[0] == 's' && instruc[1] == 's')
	{
		swap(&a);
		swap(&b);
	}
	if (instruc[0] == 'p' && instruc[1])
		push(&a, &b, instruc[1]);
	if (instruc[0] == 'r' && instruc[1] == 'a')
		rotate(&a);
	if (instruc[0] == 'r' && instruc[1] == 'b')
		rotate(&b);
	if (instruc[0] == 'r' && instruc[1] == 'r')
	{
		rotate(&a);
		rotate(&b);
	}
	if (instruc[0] == 'r' && instruc[1] == 'r' && instruc[1] == 'a')
		reverse_rotate(&a);
	if (instruc[0] == 'r' && instruc[1] == 'r' && instruc[1] == 'b')
		reverse_rotate(&b);
	if (instruc[0] == 'r' && instruc[1] == 'r' && instruc[1] == 'r')
	{
		reverse_rotate(&a);
		reverse_rotate(&b);
	}

}*/

int	ft_print_stacks(t_stack *a, t_stack *b)
{
	t_stack_node	*el;

	el = malloc(sizeof(t_stack_node *));
	if (!el)
		return (1);
	printf("StackA:\n");
	int	i = 0;
	if (a->size == 0)
		printf("%s", "Pile a vide.\n");
	else
	{
		el = a->first;
		while (i < a->size)
		{
			printf("Value : %d\nIndex : %d\n\n", el->val, el->ind);
			i++;
			el = el->next;
		}
	}
	printf("\nStackB:\n");
	i = 0;
	if (b->size == 0)
		printf("%s", "Pile b vide.\n");
	else
	{
		el = b->first;
		while (i < b->size)
		{
			printf("Value : %d\nIndex : %d\n\n", el->val, el->ind);
			i++;
			el = el->next;
		}
	}
	return (0);
}

#include <unistd.h>
int main()
{
	t_stack *a;
	t_stack *b;
	char **content_a;
	char **content_b;

	a = (t_stack *)malloc(sizeof(t_stack *));
	b = (t_stack *)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (1);
	a->first = NULL;
	b->first = NULL;

	content_a = ft_split("0 1 2 3", ' '); 
	content_b = ft_split("", ' ');
	if (!content_a || !content_b) 
    	return (printf("Error: ft_split failed\n"), 1);
	a->size = ft_avlen(content_a);
	b->size = ft_avlen(content_b);
	if (a->size)
		a = ft_fill(&a, content_a);
	if (b->size)	
		b = ft_fill(&b, content_b);

	ft_print_stacks(a, b);

	//swap(&a);
	//rotate(&a);
	//reverse_rotate(&a);




	
	ft_print_stacks(a, b);

	//char *instruction;
	//instruction = get_next_line(STDIN_FILENO);
	//verif_instruction(instruction);

	return (0);
}