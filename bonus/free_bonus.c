/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:43:45 by henrik            #+#    #+#             */
/*   Updated: 2023/08/08 15:07:03 by henrik           ###   ########lyon.fr   */
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
	free(pipex->cmd);
	free(pipex->cmd_path);
	exit (EXIT_FAILURE);
}
void	ft_free_path(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
}
void	ft_free_all(t_bonus *pipex)
{
	ft_free_path(pipex);
	ft_close_fd(pipex);
	if (pipex->heredoc == 1)
		unlink(".heredoc_tmp");
}
