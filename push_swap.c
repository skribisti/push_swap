/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:48:21 by norabino          #+#    #+#             */
/*   Updated: 2024/12/02 13:50:09 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap()
{
	stack			a; // Init of stacks
	stack			b;
	long int		*arg;
	int				len_a

	a = NULL;
	b = NULL;
	if () // Input errors
		return(0); // Error
	if () // String input, call split
		;
	while (arg[i]) // Add nodes to a
	{
		if (arg[i]) // Check int overflow, syntax errs, dups, etc..
			return (free(a), NULL);
		if (arg[i] >= -2147483647 && arg[i] <= 2147483647)
			; // Check if arg[i] is long int, else convert string to long int
		// Append nodes to a
	}
	len_a = stack_len(a);
	if (!ft_is_sorted(a))
	{
		if (len_a == 2)
			; //swap the 2 numbers
		if (len_a == 3)
			; // sort three algo
		if (len_a > 3)
			; // Turk algo
	}
	// clean up stack
	return (len_a);
}