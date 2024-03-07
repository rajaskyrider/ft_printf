/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:31 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/07 11:15:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*deal_d(char *ans, int len, int width)
{
	char	*new;

	new = (char *)ft_calloc((width + 1), sizeof(char));
	ft_strlcpy(new, ans, len + 1);
	free(ans);
	ft_memmove(new + (width - len), new, len);
	ft_memset(new, ' ', (size_t)(width - len));
	return (new);
}

int		check_null(char *ans)
{
	int	flag;

	flag = 0;
	if  (ans[0] == 0)
		flag = 1;
	return (flag);
}

void	deal_c(char *ans, char c, int *count, int width)
{
	int		len;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	len = ft_strlen(ans);
	if (c == 'c')
		flag = check_null(ans);
	if (len < width)
	{
		ft_memmove(ans + (width - len), ans, len);
		ft_memset(ans, ' ', (size_t)(width - len));
	}
	len = ft_strlen(ans);
	if (c == 'c' && flag == 1)
	{
		while(i < len - 1)
		{
			*count += write(1, &ans[i], 1);
			i++;
		}
		*count += write(1, "\0", 1);
	}
	else
		ft_putstr_count(ans, count);
}

void	ft_printspaces(va_list *ap, int *count, const char **format)
{
	int		width;
	char	c;
	char	*ans;
	int		len;

	if (**format != ' ')
		(*format)--;
	width = get_width(format);
	c = **format;
	ans = b_format_sorter((char []){c, ' '}, ap, \
							(int *[]){&width, count}, format);
	if (c != **format)
		return ;
	len = ft_strlen(ans);
	if (width == 0 && (c == 'd' || c == 'i') && !(check_negative(ans)))
		ans = deal_d(ans, len, len + 1);
	deal_c(ans, c, count, width);
	free (ans);
}
