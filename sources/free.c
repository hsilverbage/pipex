/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:53:56 by henrik            #+#    #+#             */
/*   Updated: 2023/08/08 14:55:33 by henrik           ###   ########lyon.fr   */
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
