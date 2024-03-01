/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savenbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:23:40 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 17:53:54 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_str(int nbr, int width)
{
	char	*ans;
	char	*str;

	if (width == 0)
		width = int_counter(nbr);
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	str = ft_itoa(nbr);
	ft_strlcpy(ans, str, width + 1);
	free(str);
	return (ans);
}

char	*ft_putnbr_u_str(unsigned int nbr, int width)
{
	char	*ans;
	char	*str;

	if (width == 0)
		width = int_counter(nbr);
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	str = ft_itoa(nbr);
	ft_strlcpy(ans, str, width + 1);
	free(str);
	return (ans);
}

static void	base_count(unsigned long nbr, int *width)
{
	if (nbr >= 16)
	{
		base_count(nbr / 16, width);
	}
	*width++;
}

void	ft_savebase(unsigned int size, char *base, unsigned long nbr, char *ans)
{
	int		i;
	int		start;
	int		end;
	char	temp;

	i = 0;
	start = 0;
	while (nbr >= size)
	{
		ans[i++] = base[nbr % size];
		nbr /= size;
	}
	ans[i++] = base[nbr % size];
	end = i - 1;
    	while (start < end) 
	{
		temp = ans[start];
		ans[start] = ans[end];
		ans[end] = temp;
		start++;
		end--;
	}
	ans[i] = 0;
}

char	*ft_pb_str(unsigned int nbr, char *base, int width)
{
	char				*ans;
	unsigned long		n;
	unsigned int		size;

	n = (unsigned long)nbr;
	if (width == 0)
		base_count(n, &width);
	ans = (char *)malloc(sizeof(char) * (width + 1));
	if (!ans)
		return (NULL);
	size = 16;
	ft_savebase(size, base, n, ans);
	return (ans);
}
