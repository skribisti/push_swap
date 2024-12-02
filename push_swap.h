/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:31:31 by norabino          #+#    #+#             */
/*   Updated: 2024/12/02 16:54:51 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct t_stack
{
	int long		*value;
	struct node		*prev;
	struct node		*next;
}	t_stack;
