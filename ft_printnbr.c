/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:07:54 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/28 13:33:46 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_count(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putnbr_count(int nbr, int *count)
{
	ft_putnbr_fd(nbr, 1);
	*count += int_count(nbr);
}

void	ft_putnbr_u_count(unsigned int nbr, int *count)
{
	if (nbr >= 10)
		ft_putnbr_u_count(nbr / 10, count);
	ft_putchar_count((nbr % 10) + '0', count);
}

void	ft_putbase(int size, char *base, unsigned long nbr, int *count)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= size)
	{
		ft_putbase(size, base, nbr / size, count);
	}
	*count += write (1, &base[nbr % size], 1);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *count)
{
        unsigned long	n;
        int		size;

	n = (unsigned long)nbr;
	size = 16;
	ft_putbase(size, base, n, count);
}
