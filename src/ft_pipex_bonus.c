/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:28:35 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/24 18:28:36 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_list;

	cmd_list = ft_split(cmd, ' ');
	if (!cmd_list)
		error_exit();
	path = get_path(cmd_list[0], envp);
	if (execve(path, cmd_list, envp) < 0)
	{
		free_list(cmd_list);
		error_exit();
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == *s2 || n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	error_exit(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}
