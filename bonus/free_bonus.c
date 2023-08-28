/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:43:45 by henrik            #+#    #+#             */
/*   Updated: 2023/08/28 18:47:28 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_fd(t_bonus *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	ft_free_cmd(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i])
		free(pipex->cmd[i++]);
	if ((pipex->cmd))
		free(pipex->cmd);
	if (pipex->fd)
		free(pipex->fd);
	exit (EXIT_FAILURE);
}

void	ft_free_path(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
	pipex->path = NULL;
}

void	ft_free_all(t_bonus *pipex)
{
	ft_free_path(pipex);
	ft_close_fd(pipex);
	if (pipex->heredoc == 1)
		unlink(".heredoc_tmp");
}

void	ft_error(t_bonus *pipex)
{
	perror("Error :");
	ft_free_path(pipex);
	exit (EXIT_FAILURE);
}
