/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:18:23 by norabino          #+#    #+#             */
/*   Updated: 2025/01/23 10:17:45 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_read_to_remainder(int fd, char *remainder);

int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif
