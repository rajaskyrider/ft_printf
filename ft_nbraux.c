/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbraux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:01:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/04 19:12:39 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_u_count(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*ans;
	size_t	count;

	count = int_u_count(n);
	ans = (char *)malloc(sizeof(char) * (count + 1));
	if (!ans)
		return (NULL);
	ans[count] = '\0';
	count--;
	if (n == 0)
		ans[0] = '0';
	while (n != 0)
	{
		ans[count] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (ans);
}


int	check_negative(char *ans)
{
	int	i;

	i = 0;
	while(ans[i])
	{
		if (ans[i] == '-')
			return (1);
		i++;
	}
	return (0);
}