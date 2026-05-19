/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/19 19:32:33 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_line(char *buffer, int fd)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	return (bytes);
}

char	*ft_get_excess(char *store, char *str)
{
	int		pos;
	char	*excess;
	
	pos = 0;
	while (str[pos + 1])
		excess[pos] = str[pos + 1];
	return (excess);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*line;
	char		*excess;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store, '\n') && ft_read_line(buffer, fd))
	{
		store = ft_strjoin(store, buffer);
		free (buffer);
	}
	store = ft_get_excess(store, ft_strchr(store, '\n'));
	return (line);
}
