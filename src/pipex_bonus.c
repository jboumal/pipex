/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:24:01 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/28 11:33:08 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	pipex(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		status;

	if (pipe(pipe_fd) < 0)
		error_exit();
	pid = fork();
	if (!pid)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		exec_cmd(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(-1, &status, 0);
	}
}

int	start_pipex(int argc, char **argv, char **envp, int *fd)
{
	int	fd_in;
	int	fd_out;
	int	i;

	fd_in = fd[0];
	fd_out = fd[1];
	dup2(fd_in, 0);
	close(fd_in);
	pipex(argv[2], envp);
	i = 2;
	while (++i < argc - 2)
		pipex(argv[i], envp);
	dup2(fd_out, 1);
	close(fd_out);
	if (!fork())
		exec_cmd(argv[argc - 2], envp);
	return (0);
}

void	create_tmp_file(char *eof)
{
	int		fd;
	char	*line;

	fd = open(".tmp_pipex", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		error_exit();
	line = get_next_line(0);
	while (line && (ft_strncmp(line, eof, ft_strlen(eof)) != 0
		|| ft_strlen(eof) + 1 != ft_strlen(line)))
	{
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	close (fd);
}

int	open_files(int argc, char **argv, int *fd_in, int *fd_out)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc != 6)
		{
			write (1, "Pipex with here_doc takes 5 arguments\n", 38);
			exit (EXIT_SUCCESS);
		}
		create_tmp_file(argv[2]);
		*fd_in = open(".tmp_pipex", O_RDONLY);
		*fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (*fd_in < 0 || *fd_out < 0)
			error_exit();
		return (1);
	}
	else
	{
		*fd_in = open(argv[1], O_RDONLY);
		*fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (*fd_in < 0 || *fd_out < 0)
			error_exit();
		return (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	here_doc;

	if (argc < 5)
	{
		write (1, "Pipex takes 4 arguments\n", 24);
		return (0);
	}
	here_doc = open_files(argc, argv, fd, fd + 1);
	if (here_doc)
	{
		argv ++;
		argc --;
	}
	start_pipex(argc, argv, envp, fd);
	if (here_doc)
		unlink(".tmp_pipex");
	return (0);
}
