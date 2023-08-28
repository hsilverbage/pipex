/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:22:34 by hsilverb          #+#    #+#             */
/*   Updated: 2023/08/28 16:36:40 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_struct
{
	char		**path;
	char		**cmd;
	char		*cmd_path;
	int			infile;
	int			outfile;
	int			fd[2];
	pid_t		pid;
}				t_struct;

void	ft_process_cmd2(t_struct *pipex, char **argv);
void	ft_process_cmd1(t_struct *pipex, char **argv);

void	ft_free_all(t_struct *pipex);
void	ft_free_cmd(t_struct *pipex);
void	ft_close_fd(t_struct *pipex);

#endif
