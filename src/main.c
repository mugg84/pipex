/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:23:58 by mmughedd          #+#    #+#             */
/*   Updated: 2024/03/05 09:24:03 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(INPUT_ERROR));
	pipex.r_file = open(argv[1], O_RDONLY);
	if (pipex.r_file < 0)
		error_msg(INFILE_ERROR);
	pipex.w_file = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex.w_file < 0)
		error_msg(OUTFILE_ERROR);
	if (pipe(pipex.pipe) < 0)
		error_msg(PIPE_ERROR);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		process_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		process_two(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
