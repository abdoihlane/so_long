/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:37:53 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 18:38:06 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*dup;

	c = 0;
	while (s1[c] != '\0')
		c++;
	dup = (char *)malloc(c + 1);
	if (!dup)
		return (NULL);
	c = 0;
	while (s1[c] != '\0')
	{
		dup[c] = s1[c];
		c++;
	}
	dup[c] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	l;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	l = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (s[l] != '\0')
	{
		l++;
	}
	if (dstsize != 0)
	{
		while (s[i] != '\0' && i < dstsize - 1)
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (l);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}
