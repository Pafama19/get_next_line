/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/19 12:53:26 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	int			bytes;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(store);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	store = ft_strjoin(store, buffer);
	if (ft_strchr(store, '\n'))
		line = ft_extract_line(store);
	return (line);
}
