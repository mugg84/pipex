/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:54:27 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/27 12:59:13 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_paths(char *envp[])
{
	while (*envp)
	{
		if (!ft_strncmp("PATH", *envp, 4))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	display_err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	wrong_args(int n)
{
	if (n == 1)
	{
		ft_printf("Error: Wrong argument number\n");
		ft_printf("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	exit(0);
}

char	*get_command(char *cmd, char *paths[])
{
	char	*tmp;
	char	*command;
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(command, 0))
			return (command);
		free(command);
		*paths++;
	}
	return (NULL);
}

void	child_process(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.pipe[0]);
	pipex.r_file = open(argv[1], O_RDONLY);
	if (pipex.r_file == -1)
		display_err("Error: Something wrong with r_file\n");
	dup2(pipex.r_file, 0);
	dup2(pipex.pipe[1], 1);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_args[0], pipex.cmd_paths);
	if (!pipex.cmd)
		display_err("Error: First command not available\n");
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	parent_process(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.pipe[1]);
	pipex.w_file = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.w_file == -1)
		display_err("Error: Something wrong with w_file\n");
	dup2(pipex.pipe[0], 0);
	dup2(pipex.w_file, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_args[0], pipex.cmd_paths);
	if (!pipex.cmd)
		display_err("Error: Second command not available\n");
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (pipe(pipex.pipe) == -1)
		display_err("Error: pipe\n");
	
	if (argc == 5)
	{
		pipex.paths = find_paths(envp);
		if (!pipex.paths)
			display_err("Error: No path available\n");
		pipex.cmd_paths = ft_split(pipex.paths, ':');
		if (pipe(pipex.pipe) == -1)
			display_err("Error: Something wrong with pipe\n");
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			display_err("Error: Something wrong with fork\n");
		if (!pipex.pid1)
			child_process(pipex, argv, envp); //where to close pipe[1]?
		waitpid(pipex.pid1, NULL, 0);
		parent_process(pipex, argv, envp);
		close(pipex.pipe[0]);
		close(pipex.pipe[1]);
	}
	else
		wrong_args(1);
	return (0);
}
