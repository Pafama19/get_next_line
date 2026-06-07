/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/06/07 13:23:04 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_line(char *buffer, int fd)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
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
	if (len == 1)
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

	pos = 0;
	len = 0;
	if (!store || !store[0])
		return (NULL);
	if (store[0] != '\n')
	{
		while (store[len] && store[len] != '\n')
			len++;
		line = malloc(sizeof(char) * (len + 2));
		if (!line)
			return (NULL);
	}
	else
		line = malloc(sizeof (char) * 2);
	while (pos <= len)
	{
		line[pos] = store[pos];
		pos++;
	}
	line[pos] = '\0';
	return (line);
}

char	*ft_make_line(char **store)
{
	char	*new_line;
	char	*excess;

	if (!*store)
		return (NULL);
	new_line = ft_extract_line(*store);
	excess = ft_get_excess(ft_strchr(*store, '\n'));
	free (*store);
	*store = excess;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*tmp;
	int			bytes;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE == __INT_MAX__ || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = ft_read_line(buffer, fd);
	while (bytes > 0)
	{
		tmp = ft_strjoin(store, buffer);
		free (store);
		store = tmp;
		if (ft_strchr(store, '\n'))
		{
			free (buffer);
			return (ft_make_line(&store));
		}
		bytes = ft_read_line(buffer, fd);
	}
	return (ft_error_eof(&store, buffer, bytes));
}
