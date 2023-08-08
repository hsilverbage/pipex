/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:17:03 by henrik            #+#    #+#             */
/*   Updated: 2023/08/08 11:49:50 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_open_heredoc(t_bonus *pipex, char **argv, int argc)
{
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		perror("Error :");
		ft_free_path(pipex);
		exit (EXIT_FAILURE);
	}
	pipex->outfile = open(argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
	if (pipex->outfile < 0)
	{
		perror("Error");
		unlink(".heredoc_tmp");
		close(pipex->infile);
		ft_free_path(pipex);
		exit (EXIT_FAILURE);
	}
}

void	ft_here_doc(t_bonus *pipex, char **argv, int argc)
{
	char	*buf;

	pipex->limiter = argv[2];
	pipex->file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex->file < 0)
	{
		perror("Error :");
		ft_free_path(pipex);
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(STDIN_FILENO);
		if (ft_strncmp(pipex->limiter, buf, ft_strlen(pipex->limiter) + 1) == 0)
			break ;
		write(pipex->file, buf, ft_strlen(buf));
		write(pipex->file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(pipex->file);
	ft_open_heredoc(pipex, argv, argc);
}

