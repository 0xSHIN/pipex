/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 07:33:47 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/02 23:49:47 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putnbr_base(unsigned long long int nb, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		write(2, &base[nb % 16], 1);
	}
	else
		write(2, &base[nb], 1);
}

void	ft_unsigned_putnbr(unsigned int n)
{
	unsigned long long int	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_unsigned_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr % 10 + '0');
}

void	ft_putnbr(int n)
{
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(2, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr % 10 + '0');
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
