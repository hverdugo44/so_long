# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:56:26 by hverdugo          #+#    #+#              #
#    Updated: 2025/01/09 14:12:45 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = SRC/get_next_line.c SRC/stack.c SRC/eval.c SRC/utils1.c SRC/main.c

LIBFT = libft.a

INCLUDE = INC/so_long.h INC/libft.h

FLAGS = -Wall -Wextra -Werror -g

CC = cc

OFILES = $(SRC:.c=.o)

all: libft_compile $(NAME)

libft_compile:
	make -C libft
	cp libft/libft.a .

$(NAME): $(OFILES)
	$(CC) $(OFILES) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

/*$(NAME): $(OFILES) $(INCLUDE) Makefile
	$(CC) $(OFILES) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)*/

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
