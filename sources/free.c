/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:53:56 by henrik            #+#    #+#             */
/*   Updated: 2023/08/28 19:08:54 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_struct *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	ft_free_cmd(t_struct *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i])
		free(pipex->cmd[i++]);
	free(pipex->cmd);
	exit (EXIT_FAILURE);
}

void	ft_free_all(t_struct *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
	ft_close_fd(pipex);
}

void	ft_close_dup(t_struct *pipex)
{
	close(pipex->dup_close_1);
	close(pipex->dup_close_2);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	ft_free_all(pipex);
	ft_free_cmd(pipex);
}
