/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:40:06 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/27 10:53:15 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_count(char c, int *count)
{
	ft_putchar_fd(c, 1);
	*count++;
}

void	ft_putstr_count(char *str, int *count)
{
	if (!s)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
