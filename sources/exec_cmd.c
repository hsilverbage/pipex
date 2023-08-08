/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:55:13 by henrik            #+#    #+#             */
/*   Updated: 2023/08/05 00:50:36 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_init_cmd_path(t_struct *pipex, char *cmd)
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
void	ft_process_cmd1(t_struct *pipex, char **argv)
{
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	pipex->cmd = ft_split(argv[2], ' ');
	pipex->cmd_path = ft_init_cmd_path(pipex, pipex->cmd[0]);
	if (!pipex->cmd_path)
	{
		ft_putstr_fd("Error : command not found\n", STDERR_FILENO);
		ft_free_cmd(pipex);
	}
	if (execve(pipex->cmd_path, pipex->cmd, NULL) == -1) // CHECK IF DOUBLE FREE
	{
		perror("Error : command not found\n");
		ft_free_cmd(pipex);
	}
}

void	ft_process_cmd2(t_struct *pipex, char **argv)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[1]);
	pipex->cmd = ft_split(argv[3], ' ');
	pipex->cmd_path = ft_init_cmd_path(pipex, pipex->cmd[0]);
	if (!pipex->cmd_path)
	{
		ft_putstr_fd("Error : command not found\n", STDERR_FILENO);
		ft_free_cmd(pipex);
	}
	if (execve(pipex->cmd_path, pipex->cmd, NULL) == -1)
	{
		perror("Error : command not found\n");
		ft_free_cmd(pipex);
	}
}
