/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:44:31 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/06 14:58:49 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char *buf, char *rea)
{
	char	*temp;

	temp = ft_strjoin(buf, rea);
	free(rea);
	free(buf);
	return (temp);
}

char	*get_line(char *buf)
{
	char	*line;
	char	*aux;

	if (!buf || !buf[0])
		return (NULL);
	aux = ft_strchr(buf, '\n');
	if (aux)
		line = ft_substr(buf, 1 + aux - buf);
	else
		line = ft_substr(buf, ft_strlen(buf));
	return (line);
}

char	*next_line(char *buf)
{
	char	*c;

	c = ft_strchr(buf, '\n');
	if (c)
	{
		if (*c == '\n')
			c++;
		c = ft_substr(c, ft_strlen(c));
	}
	free(buf);
	return (c);
}

char	*reader(int fd, char *buf)
{
	int		rbuf;
	char	*rfile;

	if (!buf)
		buf = ft_calloc(1, 1);
	rbuf = 1;
	rfile = ft_calloc(sizeof (char), (BUFFER_SIZE + 1));
	while (rbuf > 0)
	{
		rbuf = read(fd, rfile, BUFFER_SIZE);
		if (rbuf < 1)
		{
			free(rfile);
			if (buf && rbuf == 0)
				return (buf);
			return (NULL);
		}
		rfile[rbuf] = 0;
		buf = ft_free(buf, rfile);
		if (ft_strchr(buf, '\n'))
			return (buf);
	}
	free(rfile);
	rfile = NULL;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (buf && !buf[0])
			free(buf);
		return (NULL);
	}
	buf = reader(fd, buf);
	if (!buf || !buf[0])
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	line = get_line(buf);
	buf = next_line(buf);
	return (line);
}
