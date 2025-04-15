# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 12:07:24 by syanak            #+#    #+#              #
#    Updated: 2025/04/14 13:50:34 by syanak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Derleyici ve bayraklar
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Kaynak ve nesne dosyaları
SRC = accessibility_controls.c get_next_line.c close_window.c exit_game.c init_map.c map_checker.c map_reachable.c read_map.c render_map.c so_long.c
OBJ = $(SRC:.c=.o)

# Çıktı dosyası
EXEC = so_long

# Libft ve MinilibX
LIBFT_DIR = ./libs/libft
MLX_DIR = ./libs/minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Linux için X11 kütüphaneleri
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Derleme işlemleri
all: $(EXEC)

$(EXEC): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -o $(EXEC) $(LIBFT) $(MLX_FLAGS)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

# Libleri derle
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

# Temizleme işlemleri
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(EXEC)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
