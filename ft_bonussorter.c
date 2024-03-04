/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonussorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 11:41:26 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*b_format_sorter(char c, va_list *ap, int width, const char **format)
{
	char	*ans;
	int		w;

	ans = NULL;
	w = width;
	if (c == 'c')
		ans = ft_putchar_str(va_arg(*ap, int), width);
	else if (c == 's')
		ans = ft_putstr_str(va_arg(*ap, char *), width);
	else if (c == 'p')
		ans = ft_putmem_str(va_arg(*ap, void *), width);
	else if (c == 'd' || c == 'i')
		ans = ft_putnbr_str(va_arg(*ap, int), width);
	else if (c == 'u')
		ans = ft_putnbr_u_str(va_arg(*ap, unsigned int), width);
	else if (c == 'X')
		ans = ft_pb_str(va_arg(*ap, unsigned int), "0123456789ABCDEF", w);
	else if (c == 'x')
		ans = ft_pb_str(va_arg(*ap, unsigned int), "0123456789abcdef", w);
	else if (c == '%')
		ans = ft_putchar_str('%', width);
	else
		flag_sorter(c, ap, format);
	return (ans);
}
