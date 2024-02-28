/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:38:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/28 20:13:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(const char **format)
{
	int	width;

	width = 0;
	while (ft_isnum(**format))
	{
		width = (width * 10) + (**format - '0');
		(*format)++;
	}
	return (width);
}

void	ft_leftjust(va_list ap, int *count, const char **format)
{
	int		width;
	char	c;
	int		start;
	int		end;
	int		diff;

	if ((format + 1) == '0')
	{
		ft_zeropad(ap, count, format, 1);
		return ;
	}
	width = get_width(*(++format));
	c = **format;
	start = *count;
	format_sorter(c, ap, count, format);
	end = *count;
	diff = end - start;
	while (diff >= width)
	{
		count += write(1, '-', 1);
		diff--;
	}
	
}

void	ft_zeropad(va_list ap, int *count, const char **format, int flag)
{
	
}

void	ft_precision(va_list ap, int *count, const char **format)
{

}
