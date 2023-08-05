/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:49:39 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:33:12 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_u(va_list arguments)
{
	unsigned long long	nbr;

	nbr = va_arg(arguments, unsigned int);
	ft_unsigned_putnbr(nbr);
	return (ft_countnbr(nbr));
}
