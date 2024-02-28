# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:57:24 by rpandipe          #+#    #+#              #
#    Updated: 2024/02/28 15:59:01 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAG		= -Wall -Werror -Wextra
CPPFLAGS	= -I libft
RM		= rm -rf
SRCS		= ft_printf.c ft_printstr.c ft_printnbr.c ft_printmem.c
OBJS		= $(SRCS:.c=.o)
NAME		= libftprintf.a
LIBC		= ar rcs


all: $(NAME)

$(NAME) : $(OBJS) libft/libft.a
	cp libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o  $@

libft/libft.a:
	cd libft && $(MAKE)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS)

fclean:	clean 
	cd libft && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean libft/libft.a fclean re
