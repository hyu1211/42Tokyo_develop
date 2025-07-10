# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 18:56:10 by yuharada          #+#    #+#              #
#    Updated: 2025/07/05 18:47:33 by yuharada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c output_1.c output_2.c output_3.c output_4.c

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Werror -Wextra 

RM			= rm -f
AR			= ar rcs

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) libft.a
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re