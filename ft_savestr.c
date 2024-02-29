/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/29 15:22:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putchar_str(char c, int width)
{
	char	*ans;

	if (width == 0)
		width = 1;
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	ans[0] = c;
	ans[1] = 0;
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
