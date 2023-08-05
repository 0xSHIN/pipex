/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:54:27 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:32:14 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_x(va_list arguments)
{
	unsigned long long int	address;

	address = (unsigned long long int)va_arg(arguments, unsigned int);
	ft_putnbr_base(address, "0123456789abcdef");
	return (ft_counthex(address));
}
