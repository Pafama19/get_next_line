/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <pabfajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:06:57 by pabfajar          #+#    #+#             */
/*   Updated: 2026/05/18 19:05:23 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	char		*printstr;

	if (BUFFER_SIZE <= 0 || fd <= 0)
	{
		free(store);
		return (NULL);
	}
	
	return (printstr);
}