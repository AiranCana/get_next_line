/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:38:56 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/10 10:18:57 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *buf, char *rea, int rbuf)
{
	char	*temp;

	rea[rbuf] = 0;
	if (!buf)
		return (ft_substr(rea, ft_strlen(rea)));
	temp = ft_strjoin(buf, rea);
	if (buf)
		free(buf);
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
	return (line);
}

static char	*nline(char *buf)
{
	char	*c;

	if (!buf[0] || (buf[0] == 'n' && !buf[1]))
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
		buf = join(buf, rfile, rbuf);
		if (ft_strchr(buf, '\n'))
		{
			free (rfile);
			return (buf);
		}
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
		return (NULL);
	buf = reader(fd, buf);
	if (!buf)
		return (NULL);
	line = gline(buf);
	buf = nline(buf);
	return (line);
}
///=∂/\/\[](_)§ /\/\@|V †|-|@¯|¯ /-/!570®1<|-\£1_`/ ¢@/\/\ε vv!7}{ ???
//A