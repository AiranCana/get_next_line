/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:37:47 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/09 10:37:50 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int leter);
char	*ft_substr(char *s, size_t len);
char	*get_next_line(int fd);

void	*ft_calloc(size_t type, size_t len);

#endif
