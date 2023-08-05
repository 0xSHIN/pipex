/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 02:44:38 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 17:17:15 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**cmds;
	int		nbcmd;
	char	**envp;
	char	*in_file;
	char	*out_file;
	int		prev;
	int		fd[2];
	int		pid[1024];
	int		here_doc;
}	t_pipex;

void	*exec_pipe(t_pipex *pipex);
void	child_process(t_pipex *pipex, int i);
void	parent_process(t_pipex *pipex, int i);
void	free_command(char **command);
int		open_fd(t_pipex *pipex, int i);
char	*get_path(t_pipex *pipex, char *command);
char	**get_true_path(char **envp);
void	redirect(t_pipex *pipex, int i);
void	*exec_pipe(t_pipex *pipex);
void	here_doc(char *filename, char *delimiter);

#endif
