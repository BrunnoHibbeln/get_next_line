/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:39:15 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/05/27 16:39:15 by bhibbeln         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	char	*first;

	first = NULL;
	while (*s)
	{
		if (*s == (char)c)
			return (first = (char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (first);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;
	
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s_copy;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	s_copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_copy)
		return (NULL);
	while (s[i])
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
