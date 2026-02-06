/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:07:44 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/06 12:33:17 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int leter)
{
	char	*s;

	s = (char *) str;
	while (*s && *s != leter)
		s++;
	if (*s == leter)
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, size_t len)
{
	char	*line;
	size_t	post;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	post = 0;
	while (post < len)
	{
		line[post] = s[post];
		post++;
	}
	line[post] = '\0';
	return (line);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t		lon;
	char		*str;
	long long	count;
	int			aux;

	count = -1;
	lon = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof (char) * (lon + 1));
	if (!str || (!str1 && !str2 && !str2[0]))
		return (NULL);
	while (++count > -1 && str1[count])
		str[count] = str1[count];
	aux = count;
	count = -1;
	while (++count > -1 && str2[count])
		str[count + aux] = str2[count];
	str[lon] = '\0';
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (str);
}

void	*ft_calloc(size_t type, size_t len)
{
	char	*sol;
	size_t	tlen;
	size_t	count;

	if (!type || !len)
		return (NULL);
	tlen = type * len;
	sol = malloc(tlen);
	if (!sol)
		return (NULL);
	count = 0;
	while (count < tlen)
	{
		sol[count] = 0;
		count++;
	}
	return (sol);
}
