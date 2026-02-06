/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:11:18 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/06 14:29:11 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 26
# endif

char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int leter);
char	*ft_substr(char *s, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t type, size_t len);
char	*get_next_line(int fd);

#endif
