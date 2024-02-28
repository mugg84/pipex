/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:57:41 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/27 11:04:59 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	int		pipe[2];
	int		r_file;
	int		w_file;
	char	*cmd;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
} t_pipex;

#endif