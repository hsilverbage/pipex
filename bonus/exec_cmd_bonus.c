/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:44:35 by henrik            #+#    #+#             */
/*   Updated: 2023/08/28 18:46:07 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_init_cmd_path(t_bonus *pipex, char *cmd)
{
	char	*temp;
	char	*command;
	int		i;

	i = 0;
	if (access((cmd), F_OK | X_OK) == 0)
		return (cmd);
	while (pipex->path[i])
	{
		temp = ft_strjoin(pipex->path[i], "/");
		command = ft_strjoin(temp, cmd);
		free (temp);
		if (access((command), F_OK | X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	ft_close_pipes(t_bonus *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->nb_pipes))
	{
		close(pipex->fd[i]);
		i++;
	}
}

void	ft_dup2(int stdin, int stdout, t_bonus *pipex)
{
	pipex->dup_close_1 = dup2(stdin, STDIN_FILENO);
	pipex->dup_close_2 = dup2(stdout, STDOUT_FILENO);
}

void	ft_close_dup(t_bonus *pipex)
{
	close(pipex->dup_close_1);
	close(pipex->dup_close_2);
	ft_close_pipes(pipex);
	ft_free_all(pipex);
	ft_free_cmd(pipex);
}

void	ft_process_cmd(t_bonus *pipex, char **argv, int i)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if (i == 0)
			ft_dup2(pipex->infile, pipex->fd[1], pipex);
		else if (i == pipex->nb_cmd - 1)
			ft_dup2(pipex->fd[2 * i - 2], pipex->outfile, pipex);
		else
			ft_dup2(pipex->fd[2 * i - 2], pipex->fd[2 * i + 1], pipex);
		ft_close_pipes(pipex);
		pipex->cmd = ft_split(argv[i + 2 + pipex->heredoc], ' ');
		pipex->cmd_path = ft_init_cmd_path(pipex, pipex->cmd[0]);
		if (!pipex->cmd_path)
		{
			ft_putstr_fd("Error : command not found\n", STDERR_FILENO);
			ft_close_dup(pipex);
		}
		if (execve(pipex->cmd_path, pipex->cmd, NULL) == -1)
		{
			perror("Error : command not found\n");
			ft_close_dup(pipex);
		}
	}
}
