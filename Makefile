# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:57:24 by rpandipe          #+#    #+#              #
#    Updated: 2024/03/06 10:55:11 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAG		= -Wall -Werror -Wextra
CPPFLAGS	= -I libft
RM		= rm -rf
SRCS		= ft_printf.c ft_printstr.c ft_printnbr.c ft_printmem.c
SRCSB		= ft_bonus1.c ft_bonussorter.c ft_savemem.c ft_savenbr.c \
		  ft_savestr.c ft_width.c ft_nbraux.c ft_bonus2.c ft_precision.c
OBJS		= $(SRCS:.c=.o)
OBJSB		= $(SRCSB:.c=.o)
NAME		= libftprintf.a
LIBC		= ar rcs


all: $(NAME)

$(NAME) : $(OBJS) $(OBJSB) libft/libft.a
	cp libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS) $(OBJSB) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o  $@

bonus: $(NAME) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

libft/libft.a:
	cd libft && $(MAKE)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS) $(OBJSB)

fclean:	clean 
	cd libft && $(MAKE) fclean
	$(RM) $(NAME) $(bonus)

re: fclean all

.PHONY: all bonus clean libft/libft.a fclean re
