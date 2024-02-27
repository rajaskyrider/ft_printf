/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:03:56 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/27 10:54:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_sorter(char c, va_list ap, int *count, const char *format)
{
	if (c == 'c')
		ft_putchar_count(va_arg(ap, int), &count);
	else if (c == 's')
		ft_putstr_count(va_arg(ap, char *), &count);
	else
		format--;
}

int	printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(format, ap);
	while (*format)
	{
		if (*format == '%')
			format_sorter(*(++format), ap, &count, &format);
		else
			write(1, format, 1);
		format++;
	}
	return (count);
}
