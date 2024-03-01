/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:38:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 11:43:40 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(const char **format)
{
	int	width;

	width = 0;
	(*format)++;
	while (ft_isdigit(**format))
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
	char	*ans;
	int		len;

/*	if (**(format + 1) == '0')
	{
		ft_zeropad(ap, count, format, 1);
		return ;
	}*/
	width = get_width(format);
	c = **format;
	ans = b_format_sorter(c, ap, width, format);
	if (c != **format)
		return ;
	len = ft_strlen(ans);
	if (len < width)
		ft_memset(ans + len, ' ', (size_t)(width - len));
	ft_putstr_count(ans, count);
	free (ans);
}

void	ft_zeropad(va_list ap, int *count, const char **format, int flag)
{
	int		width;
	char	c;
	char	*ans;
	int		len;

	width = get_width(format);
	c == **format;
	if (c == 'c' || c == 's' || c == 'p' || c == '%')
		return ;
	ans = b_format_sorter(c, ap, width, format);
	if (c != **format)
		return ;
	len = ft_strlen(ans);
	if (len < width)
	{
		if (flag == 1)
			ft_memset(ans + len, '0', (size_t)(width - len));
		else
		{
			ft_memmove(ans + (width - len), ans, len);
			ft_memset(ans, '0', (size_t)(width - len));
		}
	}
	ft_putstr_count(ans, count);
	free(ans);
}

void	ft_precision(va_list ap, int *count, const char **format)
{
	int		width;
	char	c;
	char	*ans;
	int		len;

	width = get_width(format);
	c == **format;
	if (c == 'c' || c == 's' || c == 'p' || c == '%')
		return ;
	ans = b_format_sorter(c, ap, width, format);
	if (c != **format)
		return ;
	if (len < width)
	{
		ft_memmove(ans + (width - len), ans, len);
		ft_memset(ans, '0', (size_t)(width - len));
	}
	ft_putstr_count(ans, count);
	free(ans);
}
