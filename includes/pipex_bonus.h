/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:22:34 by hsilverb          #+#    #+#             */
/*   Updated: 2023/08/28 16:40:45 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_bonus
{
	char		**path;
	char		**cmd;
	char		*cmd_path;
	char		*limiter;
	int			infile;
	int			outfile;
	int			file;
	int			*fd;
	int			nb_cmd;
	int			nb_pipes;
	int			heredoc;
	pid_t		pid;
}				t_bonus;

void	ft_process_cmd(t_bonus *pipex, char **argv, int i);
void	ft_free_all(t_bonus *pipex);
void	ft_free_cmd(t_bonus *pipex);
void	ft_close_fd(t_bonus *pipex);
void	ft_close_pipes(t_bonus *pipex);
void	ft_here_doc(t_bonus *pipex, char **argv, int argc);
void	ft_free_path(t_bonus *pipex);
void	ft_error(t_bonus *pipex);

#endif
