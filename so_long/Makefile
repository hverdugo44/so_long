# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:56:26 by hverdugo          #+#    #+#              #
#    Updated: 2025/01/16 13:19:43 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = SRC/get_next_line.c SRC/stack.c SRC/eval.c SRC/utils1.c SRC/main.c SRC/imagenes.c SRC/delete.c SRC/movments.c SRC/get_next_line_utils.c SRC/end.c

LIBFT = libft/libft.a

INCLUDE = INC/so_long.h INC/libft.h

FLAGS = -Wall -Wextra -Werror -g

CC = cc

OFILES = $(SRC:.c=.o)

all: mlx_compile libft_compile $(NAME)

mlx_compile:
	@echo "Compilando MLX"
	@make -C mlx_linux

libft_compile:
	@echo "Compilando libreria"
	@make -C libft

%.o: %.c $(INCLUDE)
	@echo "Creando O-Files"
	@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OFILES) $(INCLUDE) Makefile
	@echo "Creando Programa"
	@$(CC) $(OFILES) $(LIBFT) mlx_linux/libmlx.a mlx_linux/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@echo "Eliminando O-Files"
	@make clean -C libft
	@make clean -C mlx_linux
	@rm -rf $(OFILES)

fclean:
	@echo "Eliminando Todo"
	@make fclean -C libft
	@make clean -C mlx_linux
	@rm -rf $(NAME) $(OFILES)

re:
	@echo "Vamos otra vez"
	@make fclean
	@make all

.PHONY: all, clean, fclean, re
