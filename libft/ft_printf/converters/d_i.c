/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:03:10 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:41:37 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_d_i(va_list arguments)
{
	long long int	nbr;

	nbr = va_arg(arguments, int);
	ft_putnbr(nbr);
	return (ft_countnbr(nbr));
}
