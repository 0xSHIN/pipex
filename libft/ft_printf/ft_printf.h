/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:57:52 by alyildiz          #+#    #+#             */
/*   Updated: 2023/05/08 07:38:08 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdio.h>
# include	<stdarg.h>
# include	<stddef.h>
# include	<stdint.h>
# include	<string.h>
# include   <stdlib.h>
# include   <stdbool.h>
# include	<unistd.h>

/* main function */
int		ft_printf(const char *str, ...);
int		flags(char c, va_list arguments);

/* print */
int		print_c(va_list arguments);
int		print_d_i(va_list arguments);
int		print_u(va_list arguments);
int		print_x(va_list arguments);
int		print_upcase_x(va_list arguments);
int		print_s(va_list arguments);
int		print_percent(void);
int		print_p(va_list arguments);

/* count */
int		ft_counthex(unsigned long long int nb);
int		ft_countnbr(long long int nb);

/* utils */
size_t	ft_strlen(const char *str);
bool	check(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putnbr_base(unsigned long long nb, char *base);
void	ft_unsigned_putnbr(unsigned int n);

#endif
