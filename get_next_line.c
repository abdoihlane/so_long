/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:21:48 by mohel-kh          #+#    #+#             */
/*   Updated: 2025/02/27 16:00:56 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*need_line(char **next)
{
	char	*temp;
	char	*line;
	size_t	i;

	if (!*next || !**next)
		return (NULL);
	i = 0;
	while ((*next)[i] != '\n' && (*next)[i] != '\0')
		i++;
	line = ft_substr(*next, 0, i);
	if (!line)
		return (NULL);
	if ((*next)[i] == '\n')
	{
		temp = ft_strdup(*next + i +1);
		free(*next);
		*next = temp;
	}
	else
	{
		free(*next);
		*next = NULL;
	}
	return (line);
}

static char	*ft_line(char *buffer, char *next, int fd)
{
	ssize_t		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		next = ft_strjoin(next, buffer);
		if (ft_strchr(next, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (!next || !*next || (bytes_read == -1))
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	return ((char *)next);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!next)
		next = ft_strdup("");
	next = ft_line(buffer, next, fd);
	free(buffer);
	buffer = NULL;
	return (need_line(&next));
}
