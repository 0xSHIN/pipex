/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 07:33:37 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/02 23:50:59 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_countnbr(long long int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
			nb /= 10;
			count++;
	}
	return (count);
}

int	ft_counthex(unsigned long long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
			nb /= 16;
			count++;
	}
	return (count);
}
