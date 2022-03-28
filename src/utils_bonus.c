/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:25:04 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/24 17:25:05 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
