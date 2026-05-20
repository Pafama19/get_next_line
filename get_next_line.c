/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/20 11:58:20 by pabfajar         ###   ########.fr       */
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
	int		len;

	if (!str)
		return (NULL);
	len = strlen(str + 1);
	pos = 0;
	excess = malloc(sizeof(char) * (len + 1));
	if (!excess)
		return (NULL);
	while (str[pos + 1])
	{
		excess[pos] = str[pos + 1];
		pos++;
	}
	excess[pos] = '\0';
	return (excess);
}

char	*ft_extract_line(char *store)
{
	int		pos;
	char	*line;
	int		len;

	pos = 0;
	len = 0;
	if (store == NULL)
		return (NULL);
	while (store[len] && store[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (store[pos])
	{
		if (store[pos] == '\n')
		{
			line[pos] = '\n';
			line[pos + 1] = '\0';
			return (line);
		}
		line[pos] = store[pos];
		pos++;
	}
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
	line = ft_extract_line(store);
	store = ft_get_excess(store, ft_strchr(store, '\n'));
	return (line);
}
