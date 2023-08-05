/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:00:16 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:32:26 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_upcase_x(va_list arguments)
{
	unsigned long	address;

	address = (unsigned long)va_arg(arguments, unsigned int);
	ft_putnbr_base(address, "0123456789ABCDEF");
	return (ft_counthex(address));
}
