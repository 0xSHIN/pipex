/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:08:25 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 20:20:40 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

/*

si c'est la premiere
si c'est la derniere
si c'est pas la premiere
si c'est pas la derniere

si i == 0
	redirect l'input depuis le fichier
si i == nbcmd - 1
	redirect l'output vers le fichier
si i != 0
	redirect l'input depuis le pipe d'avant
si i != nbcmd - 1
	redirect l'output vers le pipe d'apres

					0		1		2		3			4
./pipex Makefile  "ls -l"	"wc -l"	"avion"	"grep a" "cat" outfile

*/
char	**get_true_path(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ":"));
		i++;
	}
	return (NULL);
}

char	*get_path(t_pipex *pipex, char *command)
{
	char	**tab;
	int		j;
	char	*tmp2;
	char	*tmp;

	tab = NULL;
	j = -1;
	if (ft_strchr(command, '/') != NULL)
		return (ft_strdup(command));
	tab = get_true_path(pipex->envp);
	if (!tab)
		return (ft_printf("pipex: %s command not found\n", command), NULL);
	while (tab && tab[++j])
	{
		tmp = ft_strjoin(tab[j], "/");
		tmp2 = ft_strjoin(tmp, command);
		free(tmp);
		if (access(tmp2, F_OK | X_OK) == 0)
			return (tmp2);
		free(tmp2);
	}
	ft_printf("pipex: %s command not found\n", command);
	return (free_command(tab), NULL);
}

void	redirect(t_pipex *pipex, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open_fd(pipex, i);
		dup2(fd, 0);
		close(fd);
	}
	if (i == pipex->nbcmd - 1)
	{
		fd = open_fd(pipex, i);
		dup2(fd, 1);
		close(fd);
	}
	if (i != 0)
	{
		dup2(pipex->prev, 0);
		close(pipex->prev);
	}
	if (i != pipex->nbcmd - 1)
		dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->cmds = argv + 2;
	pipex->nbcmd = argc - 3;
	pipex->envp = envp;
	pipex->in_file = argv[1];
	pipex->out_file = argv[argc - 1];
}

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	pipex = {0};

	if (argc < 5)
		return (ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n"), 1);
	if (argc > 5)
		return (ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n"), 1);
	init_pipex(&pipex, argc, argv, envp);
	exec_pipe(&pipex);
	close(pipex.fd[0]);
	return (0);
}
