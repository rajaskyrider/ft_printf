/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:06:56 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/28 15:58:01 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mtoa(char *ans, void *ptr, int size)
{
	unsigned long long int	address;

	ans[0] = '0';
	ans[1] = 'x';
	ans[size] = 0;
	address = (unsigned long long int)ptr;
	while (address != 0)
	{
		ans[size] = "0123456789abcdef"[address % 16];
		address /= 16;
		size--;
	}
	return (ans);
}

void	ft_putmem_count(void *ptr, int *count)
{
	unsigned long long int	address;
	int						size;
	char					*ans;

	address = (unsigned long long int)ptr;
	size = 0;
	while (address != 0)
	{
		size++;
		address /= 16;
	}
	ans = (char *)malloc(sizeof(char) * (size + 3));
	if (!ans)
		return ;
	ans = ft_mtoa(ans, ptr, size + 1);
	ft_putstr_count(ans, count);
	free (ans);
}
