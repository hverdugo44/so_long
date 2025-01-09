# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:56:26 by hverdugo          #+#    #+#              #
#    Updated: 2024/12/25 21:40:33 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = get_next_line.c stack.c eval.c utils1.c

LIBFT = libft.a

INCLUDE = so_long.h

FLAGS = -Wall -Wextra -Werror -g

CC = cc

OFILES = $(SRC:.c=.o)

all: libft_compile $(NAME)

libft_compile:
	make -C libft
	cp libft/libft.a .

$(NAME): $(OFILES) $(INCLUDE) Makefile
	$(CC) $(FLAGS) $(OFILES) libft.a -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OFILES)

fclean:
	make fclean -C libft
	rm -rf $(NAME) $(OFILES) libft.a

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
