/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <jboumal@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:26:48 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/24 15:49:40 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	error_exit(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

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

void	pipex(char *cmd, char **envp, int fd_in, int fd_out)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		status;

	if (fd_out != 1)
		exec_cmd(cmd, envp);
	if (pipe(pipe_fd) < 0)
		error_exit();
	pid = fork();
	if (!pid)
	{
		if (fd_in != 0)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
		}
		exec_cmd(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(-1, &status, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
	{
		write (1, "Pipex takes 4 arguments\n", 24);
		return (0);
	}
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_in < 0 || fd_out < 0)
		error_exit();
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	pipex(argv[2], envp, fd_in, 1);
	pipex(argv[3], envp, 0, fd_out);
	close(fd_in);
	close(fd_out);
	return (0);
}
