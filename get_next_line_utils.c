/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:40:06 by pabfajar          #+#    #+#             */
/*   Updated: 2026/06/01 12:38:03 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	if (s == NULL)
		return (0);
	while (s[pos] != '\0')
		pos++;
	return (pos);
}

char	*ft_strchr(const char *str, int c)
{
	int			pos;
	const char	*aux;

	pos = 0;
	if (str == NULL)
		return (NULL);
	while (str[pos] != '\0')
	{
		if (str[pos] == (char)c)
		{
			aux = &str[pos];
			return ((char *)aux);
		}
		pos++;
	}
	if (str[pos] == (char)c)
	{
		aux = &str[pos];
		return ((char *)aux);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	dest = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	if (s1)
	{
		while (s1[j])
			dest[i++] = s1[j++];
	}
	if (s2)
	{
		while (s2[k])
			dest[i++] = s2[k++];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_error_eof(char **store, char *buffer, int bytes)
{
	char	*line;

	free(buffer);
	if (bytes < 0)
	{
		free(*store);
		*store = NULL;
		return (NULL);
	}
	if (*store && **store)
	{
		if (ft_strchr(*store, '\n'))
			return (ft_make_line(store));
		line = *store;
		*store = NULL;
		return (line);
	}
	if (*store)
	{
		free(*store);
		*store = NULL;
	}
	return (NULL);
}
