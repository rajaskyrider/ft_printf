/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:31 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 18:44:15 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspaces(va_list ap, int *count, const char **format)
{
	int		width;
	char	c;
	char	*ans;
	int		len;

	(*format)--;
	width = get_width(format);
	c = **format;
	ans = b_format_sorter(c, ap, width, format);
	if (c != **format)
		return ;
	len = ft_strlen(ans);
	if (len < width)
	{
		ft_memmove(ans + (width - len), ans, len);
		ft_memset(ans, ' ', (size_t)(width - len));
	}
	ft_putstr_count(ans, count);
	free(ans);
}