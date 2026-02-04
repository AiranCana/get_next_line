/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:44:31 by acanadil          #+#    #+#             */
/*   Updated: 2026/02/04 16:15:50 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(char *buf)
{
	int	rbuf;

	rbuf = 1;
	while (rbuf > 0)
	{
		
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buffer = reader(buffer);
	if (!buffer)
		return (NULL);
	return (line);
}
