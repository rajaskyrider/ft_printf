/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:48:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/27 19:58:39 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	format_sorter(char c, va_list ap, int *count, const char **format);
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putnbr_count(int nbr, int *count);
void	ft_putnbr_u_count(int nbr, int *count);

#endif
