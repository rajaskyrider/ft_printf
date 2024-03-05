/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:38:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/05 09:37:33 by rpandipe         ###   ########.fr       */
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

char	*padzeros(char *ans, int width, int len, char flag)
{
	int		offset;
	char	*new;

	offset = check_negative(ans);
	if (offset == 1 && flag == '.')
	{
		width = width + 1;
		if (len < width)
		{
			new = (char *)ft_calloc(width + 1, sizeof(char));
			ft_strlcpy(new, ans, width + 1);
			free(ans);
			ans = new;
		}
	}
	if (len < width)
	{
		ft_memmove(ans + offset + (width - len), ans + offset, len - offset);
		ft_memset(ans + offset, '0', (size_t)(width - len));
	}
	return (ans);
}

void	ft_leftjust(va_list *ap, int *count, const char **format)
{
	int		width;
	char	c;
	char	*ans;
	int		len;

	width = get_width(format);
	c = **format;
	ans = b_format_sorter(c, ap, width, format);
	if (c != **format)
		return ;
	if (ans[0] == 0 && c == 'c')
	{
		write(1, "\0", 1);
		*count += 1;
		width -= 1;
	}
	len = ft_strlen(ans);
	if (len < width)
	{
		//ft_memcpy(ans + width, ans + len, (size_t)(width - len));
		ft_memset(ans +  len, ' ', (size_t)(width - len));
	}
	ft_putstr_count(ans, count);
	free (ans);
}

void	ft_zeropad(va_list *ap, int *count, const char **format, int flag)
{
	int		width;
	char	c;
	char	*ans;
	int		len;
	int		offset;

	width = get_width(format);
	c = **format;
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
			ans = padzeros(ans, width, len, 'c');
	}
	ft_putstr_count(ans, count);
	free(ans);
}

void	ft_precision(va_list *ap, int *count, const char **format)
{
	int		width;
	char	c;
	char	*p_ans;
	char	*ans;
	int		len;

	width = get_width(format);
	c = **format;
	p_ans = b_format_sorter(c, ap, width, format);
	len = ft_strlen(p_ans);
	if (c != **format)
		return ;
	if (c == 's' && len > width)
	{
		ans = (char *)ft_calloc((width + 1), sizeof(char));
		ft_strlcpy(ans, p_ans, (width + 1));
		free(p_ans);
	}
	else 
		ans = p_ans;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ans = padzeros(ans, width, len, '.');
	ft_putstr_count(ans, count);
	free(ans);
}
