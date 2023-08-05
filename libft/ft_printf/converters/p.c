/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:36:37 by alyildiz          #+#    #+#             */
/*   Updated: 2023/08/02 23:49:47 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_p(va_list arguments)
{
	unsigned long	address;

	address = (unsigned long)va_arg(arguments, void *);
	if (address == 0)
		return (write(2, "(nil)", 5));
	write(2, "0x", 2);
	ft_putnbr_base(address, "0123456789abcdef");
	return (ft_counthex(address) + 2);
}
