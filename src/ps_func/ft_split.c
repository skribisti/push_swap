/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:53:32 by norabino          #+#    #+#             */
/*   Updated: 2025/02/28 15:05:53 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

char	**ft_split(char *str, char c)
{
	int		tab[3];
	char	**dst;

	if (!str)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_countwords(str, (int)c) + 1));
	if (!dst)
		return (NULL);
	ft_init_to_null(dst, ft_countwords(str, (int)c) + 1);
	tab[2] = 0;
	tab[0] = 0;
	while (str[tab[0]] && tab[2] < ft_countwords(str, (int)c))
	{
		ft_build_line(str, &tab[0], &tab[1], &c);
		dst[tab[2]] = ft_strndup(str + tab[0], tab[1] - tab[0]);
		if (dst[tab[2]] == NULL)
		{
			ft_free_dst(dst, tab[2]);
			return (NULL);
		}
		tab[0] = tab[1];
		tab[2]++;
	}
	dst[tab[2]] = 0;
	return (dst);
}
/*
ABREVIATIONS :
tab[0] = start
tab[1] = end
tab[2] = i
*/
