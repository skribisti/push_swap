/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:05:12 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 16:52:33 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_to_null(char **dst, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		dst[i] = NULL;
		i++;
	}
}

void	ft_free_dst(char **dst, int i)
{
	if (!dst)
		return ;
	while (i--)
	{
		if (dst[i])
			free(dst[i]);
	}
	free(dst);
}
