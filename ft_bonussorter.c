/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonussorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/28 20:13:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	b_format_sorter(char c, va_list ap, int *count, const char **format)
{
	if (c == 'c')
		ft_putchar_count(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr_count(va_arg(ap, char *), count);
	else if (c == 'p')
		ft_putmem_count(va_arg(ap, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putnbr_u_count(va_arg(ap, unsigned int), count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", count);
	else if (c == '%')
		ft_putchar_count('%', count);
	else
		flag_sorter(c, ap, count, format);
}

void	flag_sorter(char c, va_list ap, int *count, const char **format)
{
	if (c == '-')
		ft_leftjust(ap, count, format);
	else if (c == '0')
		ft_zeropad(ap, count, format, 0);
	else if (c == '.')
		ft_precision(ap, count, format);
	else
		(*format)--;
}
