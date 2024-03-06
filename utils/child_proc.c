/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:23:50 by mmughedd          #+#    #+#             */
/*   Updated: 2024/03/05 09:25:13 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static char	*get_command(char **paths, char *command)
{
	char	*tmp;
	char	*cmd;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, command);
		free(tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return (NULL);
}

void	process_one(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.pipe[0]);
	dup2(pipex.pipe[1], 1);
	dup2(pipex.r_file, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		msg(COMMAND_ERROR);
		free_child(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	process_two(t_pipex pipex, char *argv[], char *envp[])
{
	close(pipex.pipe[1]);
	dup2(pipex.pipe[0], 0);
	dup2(pipex.w_file, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		msg(COMMAND_ERROR);
		free_child(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
