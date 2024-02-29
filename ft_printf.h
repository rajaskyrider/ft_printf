/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:48:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/29 15:22:48 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	format_sorter(char c, va_list ap, int *count, const char **format);
int		flag_sorter(char c, va_list ap, const char **format);
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putnbr_count(int nbr, int *count);
void	ft_putnbr_u_count(unsigned int nbr, int *count);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count);
void	ft_putmem_count(void *ptr, int *count);
void	ft_leftjust(va_list ap, int *count, const char **format);
void	ft_zeropad(va_list ap, int *count, const char **format);
void	ft_precision(va_list ap, int *count, const char **format);
int		get_width(const char **format);
void	ft_leftjust(va_list ap, int *count, const char **format);
char	*b_format_sorter(char c, va_list ap, int width, const char **format);
char	*ft_putchar_str(char c, int width);
char	*ft_putstr_str(char *str, int width);
size_t	int_count(int n);

#endif
