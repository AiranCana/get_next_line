/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:44:31 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/12 15:51:55 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join(char *buf, char *rea, int rbuf)
{
	char	*temp;

	rea[rbuf] = 0;
	if (!buf)
		temp = ft_substr(rea, ft_strlen(rea));
	else
	{
		temp = ft_strjoin(buf, rea);
		free(buf);
	}
	if (!temp)
		free (rea);
	return (temp);
}

static char	*gline(char *buf)
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
	if (!line)
	{
		free (buf);
		buf = NULL;
	}
	return (line);
}

static char	*nline(char *buf)
{
	char	*c;

	if (!buf[0] || (buf[0] == '\n' && !buf[1]))
	{
		free(buf);
		return (NULL);
	}
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

static char	*reader(int fd, char *buf)
{
	int		rbuf;
	char	*rfile;

	rbuf = 1;
	rfile = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	while (rbuf > 0)
	{
		rbuf = read(fd, rfile, BUFFER_SIZE);
		if (rbuf <= 0)
		{
			going_free(rfile, NULL);
			if (rbuf == 0)
				return (buf);
			return (going_free(buf, NULL));
		}
		buf = join(buf, rfile, rbuf);
		if (!buf)
			return (NULL);
		else if (ft_strchr(buf, '\n'))
			return (going_free(rfile, buf));
	}
	free(rfile);
	rfile = NULL;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = reader(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = gline(buf[fd]);
	buf[fd] = nline(buf[fd]);
	return (line);
}
