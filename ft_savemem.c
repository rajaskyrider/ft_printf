/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savemem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:48:37 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 11:35:58 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_nil(int width)
{
	char	*ans;

	if (width == 0)
		width = ft_strlen("(nil)");
	ans = (char *)malloc(sizeof(char) * (width + 1));
	ft_strlcpy(ans, "(nil)", width + 1);
	return (ans);
}

static char	*ft_mltoa(char *ans, void *ptr)
{
	unsigned long long int	address;
	int						i;
	int						size;

	size = 0;
	address = (unsigned long long int)ptr;
	while (address != 0)
	{
		size++;
		address /= 16;
	}
	ans = (char *)malloc(sizeof(char) * (size + 3));
	ans[0] = '0';
	ans[1] = 'x';
	ans[size + 2] = 0;
	i = size + 1;
	address = (unsigned long long int)ptr;
	while (address != 0)
	{
		ans[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	return (ans);
}

char	*ft_putmem_str(void *ptr, int width)
{
	unsigned long long int	address;
	char					*ans;
	char					*temp;

	address = (unsigned long long int)ptr;
	if (address == 0)
	{
		ans = add_nil(width);
		return (ans);
	}
	if (width == 0)
	{
		while (address != 0)
		{
			width++;
			address /= 16;
		}
	}
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	temp = ft_mltoa(ans, ptr);
	ft_strlcpy(ans, temp, width + 1);
	free (temp);
	return (ans);
}
