/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:40:06 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/22 11:55:58 by pabfajar         ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *source, size_t dest_size)
{
	size_t	pos;
	size_t	dest_len;
	size_t	source_len;

	pos = 0;
	dest_len = ft_strlen(dest);
	source_len = ft_strlen(source);
	if (dest_size <= dest_len)
	{
		dest_len = dest_size;
		return (dest_size + source_len);
	}
	while ((source[pos] != '\0') && (dest_len + pos < dest_size - 1))
	{
		dest[dest_len + pos] = source[pos];
		pos++;
	}
	dest[dest_len + pos] = '\0';
	return (dest_len + source_len);
}

char	*ft_reserve_mem(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof (char) * (len_s1 + len_s2 + 1));
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	pos;

	pos = 0;
	dest = ft_reserve_mem(s1, s2);
	if (!s1)
	{
		while (s2[pos])
		{
			dest[pos] = s2[pos];
			pos++;
		}
		dest[pos] = '\0';
		return (dest);
	}
	while (s1[pos])
	{
		dest[pos] = s1[pos];
		pos++;
	}
	dest[pos] = '\0';
	ft_strlcat(dest, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	return (dest);
}
