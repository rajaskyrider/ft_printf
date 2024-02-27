# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:57:24 by rpandipe          #+#    #+#              #
#    Updated: 2024/02/27 11:35:07 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAG	= -Wall -Werror -Wextra
RM	= rm -rf
SRCS	= ft_printf.c ft_printstr.c
OBJS	= $(SRCS: .c=.o)
NAME	= libftprintf.a
LIBC	= ar rcs

all: $(NAME)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
