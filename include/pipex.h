/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:23:20 by mmughedd          #+#    #+#             */
/*   Updated: 2024/03/05 11:06:39 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "libft.h"

# define COMMAND_ERROR "Command not found\n"
# define INPUT_ERROR "Invalid number of arguments\n"
# define INFILE_ERROR "Infile"
# define PIPE_ERROR "Pipe"
# define OUTFILE_ERROR "Outfile"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		pipe[2];
	int		r_file;
	int		w_file;
}	t_pipex;

void	process_one(t_pipex pipex, char *argv[], char *envp[]);
void	process_two(t_pipex pipex, char *argv[], char *envp[]);
void	error_msg(char *err);
void	close_pipe(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
char	*find_path(char **envp);
int		msg(char *err);

#endif
