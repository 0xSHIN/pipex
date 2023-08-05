/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 02:23:30 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 15:48:42 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	child_process(t_pipex *pipex, int i)
{
	char	**cmd;
	char	*path;

	redirect(pipex, i);
	cmd = ft_split(pipex->cmds[i], " ");
	if (!cmd || !cmd[0])
		return (free_command(cmd));
	path = get_path(pipex, cmd[0]);
	if (path)
		execve(path, cmd, pipex->envp);
	return (free_command(cmd), free(path), exit(1));
}

void	parent_process(t_pipex *pipex, int i)
{
	close(pipex->fd[1]);
	if (i)
		close(pipex->prev);
	pipex->prev = pipex->fd[0];
}

void	free_command(char **command)
{
	int	i;

	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
}

int	open_fd(t_pipex *pipex, int i)
{
	int	fd;

	fd = -1;
	if (i == 0)
	{
		fd = open(pipex->in_file, O_RDONLY);
		if (fd < 0)
			return (close(pipex->fd[0]), close(pipex->fd[1])
				, perror("Error"), exit(1), fd);
	}
	if (i == pipex->nbcmd - 1)
	{
		fd = open(pipex->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
		{
			close(pipex->fd[0]);
			return (close(pipex->prev), close(pipex->fd[1])
				, perror("Error"), exit(1), fd);
		}
	}
	return (fd);
}

void	*exec_pipe(t_pipex *pipex)
{
	int		i;
	int		status;

	i = -1;
	while (++i < pipex->nbcmd)
	{
		if ((pipe(pipex->fd)) == -1)
			return (perror("Error"), NULL);
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
			return (perror("Error"), NULL);
		if (pipex->pid[i] == 0)
			child_process(pipex, i);
		else
			parent_process(pipex, i);
	}
	i = 0;
	while (i < pipex->nbcmd)
		waitpid(pipex->pid[i++], &status, 0);
	return (NULL);
}
