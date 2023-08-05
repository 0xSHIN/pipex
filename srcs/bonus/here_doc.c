/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:29:56 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 22:18:26 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	here_doc(char *filename, char *delimiter)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDWR | O_CREAT, 0666);
	if (fd < 0)
		return (perror("Error"), exit(1));
	delimiter = ft_strjoin(delimiter, "\n");
	while (1)
	{
		write(1, "heredoc> ", 10);
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	get_next_line(0, 1);
	free(delimiter);
	close(fd);
}
