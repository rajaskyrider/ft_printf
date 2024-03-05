/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonussorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:06:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/05 10:27:13 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*b_format_sorter(char c, va_list *ap, int *wc[2], const char **format)
{
	char	*ans;
	int		w;

	ans = NULL;
	w = *wc[0];
	if (c == 'c')
		ans = ft_putchar_str(va_arg(*ap, int), w);
	else if (c == 's')
		ans = ft_putstr_str(va_arg(*ap, char *), w);
	else if (c == 'p')
		ans = ft_putmem_str(va_arg(*ap, void *), w);
	else if (c == 'd' || c == 'i')
		ans = ft_putnbr_str(va_arg(*ap, int), w);
	else if (c == 'u')
		ans = ft_putnbr_u_str(va_arg(*ap, unsigned int), w);
	else if (c == 'X')
		ans = ft_pb_str(va_arg(*ap, unsigned int), "0123456789ABCDEF", w);
	else if (c == 'x')
		ans = ft_pb_str(va_arg(*ap, unsigned int), "0123456789abcdef", w);
	else if (c == '%')
		ans = ft_putchar_str('%', w);
	else
		*wc[1] += flag_sorter(c, ap, format);
	return (ans);
}
