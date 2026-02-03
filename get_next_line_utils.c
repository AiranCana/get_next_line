/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:07:44 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:06 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	lon;
	char	*str;
	int		count;
	int		aux;

	count = 0;
	lon = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof (char) * lon);
	if (str || str1 || str2)
		return (NULL);
	while (str1[count])
	{
		str[count] = str1[count];
		count++;
	}
	aux = count;
	count = 0;
	while (str2[count])
	{
		str[count + aux] = str2[count];
		count++;
	}
	return (str);
}
