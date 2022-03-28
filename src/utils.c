/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:43:33 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/16 14:43:59 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	free_list(char **list)
{
	char	**t;

	t = list;
	while (*t)
	{
		free(*t);
		t++;
	}
	free(list);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str ++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*s3;
	char	*t;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (size + 1));
	if (!s3)
		return (NULL);
	t = s3;
	while (*s1)
	{
		*t = *s1;
		t++;
		s1++;
	}
	while (*s2)
	{
		*t = *s2;
		t++;
		s2++;
	}
	*t = '\0';
	return (s3);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *) haystack);
	if (len <= 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack [i + j] == needle [j] && haystack [i + j]
			&& i + j < len)
		{
			if (!haystack [i + j] || j == ft_strlen(needle) - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i ++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{	
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i = 0;
	}
	while (src[i])
		i++;
	return (i);
}
