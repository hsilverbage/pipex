/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:21:14 by hsilverb          #+#    #+#             */
/*   Updated: 2023/08/28 19:03:50 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_args(int argc, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error : Wrong number of arguments\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (!envp[0])
	{
		ft_putstr_fd("Error : Environment not found\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

void	ft_open_fd(int argc, char **argv, t_struct *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror("Error");
		exit (EXIT_FAILURE);
	}
	pipex->outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		perror("Error");
		close(pipex->infile);
		exit (EXIT_FAILURE);
	}
}

void	ft_init_path(char **envp, t_struct *pipex)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			pipex->path = ft_split(envp[i] + 5, ':');
			return ;
		}
		i++;
	}
	ft_close_fd(pipex);
	ft_putstr_fd("Error : Path not found in environment\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	ft_error(t_struct *pipex)
{
	ft_free_all(pipex);
	perror("Error :");
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	pipex;

	ft_bzero(&pipex, sizeof(pipex));
	ft_check_args(argc, envp);
	ft_open_fd(argc, argv, &pipex);
	ft_init_path(envp, &pipex);
	if (pipe(pipex.fd) == -1)
		ft_error(&pipex);
	pipex.pid = fork();
	if (pipex.pid == -1)
		ft_error(&pipex);
	if (pipex.pid == 0)
		ft_process_cmd1(&pipex, argv);
	waitpid(pipex.pid, NULL, 0);
	pipex.pid = fork();
	if (pipex.pid == -1)
		ft_error(&pipex);
	if (pipex.pid == 0)
		ft_process_cmd2(&pipex, argv);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	waitpid(pipex.pid, NULL, 0);
	ft_free_all(&pipex);
	return (0);
}
