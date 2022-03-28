/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:24:09 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/24 17:24:11 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_list(char **list);
void	error_exit(void);

char	*get_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);

#endif
