/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:39:28 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:39:27 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	flags(char c, va_list arguments)
{
	if (c == 'c')
		return (print_c(arguments));
	else if (c == 's')
		return (print_s(arguments));
	else if (c == 'p')
		return (print_p(arguments));
	else if (c == 'd' || c == 'i')
		return (print_d_i(arguments));
	else if (c == 'u')
		return (print_u(arguments));
	else if (c == 'x')
		return (print_x(arguments));
	else if (c == 'X')
		return (print_upcase_x(arguments));
	else if (c == '%')
		return (print_percent());
	return (0);
}
