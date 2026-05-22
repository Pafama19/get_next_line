/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/22 17:56:57 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_line(char *buffer, int fd)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (0);
	buffer[bytes] = '\0';
	return (bytes);
}

char	*ft_get_excess(char *str)
{
	int		pos;
	char	*excess;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	pos = 0;
	if (len == 0)
		return (NULL);
	excess = malloc(sizeof(char) * (len));
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

	pos = -1;
	len = 0;
	if (store == NULL)
		return (NULL);
	while (store[len] && store[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (store[++pos])
	{
		if (store[pos] == '\n')
		{
			line[pos] = '\n';
			line[pos + 1] = '\0';
			return (line);
		}
		line[pos] = store[pos];
	}
	line[pos] = '\0';
	return (line);
}

char	*ft_make_line(char *store, char *buffer)
{
	char	*line;
	char	*excess;

	if (ft_strchr(store, '\n'))
	{
		line = ft_extract_line(store);
		excess = ft_get_excess(ft_strchr(store, '\n'));
		free (store);
		store = excess;
		free (buffer);
	}
	return (line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_read_line(buffer, fd) > 0)
	{
		store = ft_strjoin(store, buffer);
		if ((store != NULL))
		{
			line = ft_make_line(store, buffer);
			return (line);
		}
	}
	line = *store;
	*store = NULL;
	free (buffer);
	return (ft_end(&store));
}
