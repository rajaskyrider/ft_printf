/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:03:56 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:56 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_sorter(char c, va_list ap, int *count, const char **format)
{
	if (c == 'c')
		ft_putchar_count(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr_count(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putnbr_u_count(va_arg(ap, unsigned int), count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", count);
	else
		(*format)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			format_sorter(*(++format), ap, &count, &format);
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}
