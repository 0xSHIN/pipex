/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:15:02 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/05 17:54:54 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

int	gnl_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str)
	{	
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (1);
			i++;
		}
	}
	return (0);
}
