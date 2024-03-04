/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/04 11:22:11 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar_str(char c, int width)
{
	char	*ans;
	int		i;

	i = 1;
	if (width == 0)
		width = 1;
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	ans[0] = c;
	while (i <= width)
	{
		ans[i] = 0;
		i++;
	}
	return (ans);
}

char	*ft_putstr_str(char *str, int width)
{
	char	*ans;

	if (width == 0)
		width = ft_strlen(str);
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, str, width + 1);
	return (ans);
}
