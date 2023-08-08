/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:44:24 by henrik            #+#    #+#             */
/*   Updated: 2023/08/08 11:55:13 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_check_args(int argc, char **envp, t_bonus *pipex, char **argv)
{
	if (!envp[0])
	{
		ft_putstr_fd("Error : Environment not found\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (argc < 5)
	{
		ft_putstr_fd("Error : Too few arguments\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		pipex->heredoc = 1;
	else
		pipex->heredoc = 0;
	if (pipex->heredoc == 1 && argc < 6)
	{
		ft_putstr_fd("Error : Too few arguments\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	pipex->nb_cmd = argc - 3 - pipex->heredoc;
	pipex->nb_pipes = 2 * (pipex->nb_cmd - 1);
}

void	ft_open_fd(int argc, char **argv, t_bonus *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		ft_free_path(pipex);
		perror("Error");
		exit (EXIT_FAILURE);
	}
	pipex->outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		perror("Error");
		ft_free_path(pipex);
		close(pipex->infile);
		exit (EXIT_FAILURE);
	}
}

void	ft_init_path(char **envp, t_bonus *pipex)
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
	ft_putstr_fd("Error : Path not found in environment\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	ft_error(t_bonus *pipex)
{
	perror("Error :");
	ft_free_path(pipex);
	exit (EXIT_FAILURE);
}
void	ft_init_pipe(t_bonus *pipex)
{
	int	i;

	i = 0;
	pipex->fd = (int *)malloc(sizeof(int) * pipex->nb_pipes);
	if (!pipex->fd)
		ft_error(pipex);
	while (i < pipex->nb_cmd - 1)
	{
		if (pipe(pipex->fd + 2 * i) < 0)
			ft_error(pipex);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_bonus	pipex;
	int		i;

	i = 0;
	ft_bzero(&pipex, sizeof(pipex));
	ft_check_args(argc, envp, &pipex, argv);
	ft_init_path(envp, &pipex);
	if (pipex.heredoc == 1)
		ft_here_doc(&pipex, argv, argc);
	else
		ft_open_fd(argc, argv, &pipex);
	ft_init_pipe(&pipex);
	while (i < pipex.nb_cmd)
	{
		ft_process_cmd(&pipex, argv, i);
		i++;
	}
	ft_close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	ft_free_all(&pipex);
	return (0);
}
