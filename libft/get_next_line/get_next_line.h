/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:13:09 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 17:55:00 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		gnl_strchr(const char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_current_line(char *stash);
char	*add_left_to_stash(char *stash);
char	*get_next_line(int fd, int boolean);
int		verif(char **buffer);

#endif
