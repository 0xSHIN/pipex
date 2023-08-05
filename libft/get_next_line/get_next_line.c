/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:44:23 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 17:56:17 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*gnl_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*dest;

	len1 = 0;
	len2 = 0;
	j = 0;
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (j < len2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (free(s1), dest);
}

char	*get_current_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*add_left_to_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*left;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	left = malloc((ft_strlen(stash) - i) * sizeof(char));
	if (!left)
		return (free(stash), NULL);
	j = i + 1;
	k = 0;
	while (stash[j])
		left[k++] = stash[j++];
	left[k] = '\0';
	return (free(stash), left);
}

int	verif(char **buffer)
{
	if (BUFFER_SIZE <= 0)
		return (0);
	(*buffer) = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buffer))
		return (0);
	return (1);
}

char	*get_next_line(int fd, int boolean)
{
	static char		*stash;
	char			*line;
	char			*buffer;
	int				bytes_read;

	if (boolean == 1)
		return (free(stash), NULL);
	bytes_read = 1;
	if (!verif(&buffer))
		return (NULL);
	while (bytes_read && !gnl_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	line = get_current_line(stash);
	stash = add_left_to_stash(stash);
	return (free(buffer), line);
}

/*
   int	main(int argc, char **argv)
   {
   char	*str;
   int		fd;

   if (argc != 2)
   return (1);
   fd = open(argv[1], O_RDONLY);
   str = get_next_line(fd);
   while (str)
   {
   printf("%s", str);
   free(str);
   str = get_next_line(fd);
   }
   free(str);
   return (0);
   }
 */
