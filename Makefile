# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:35:11 by rlegan            #+#    #+#              #
#    Updated: 2019/06/04 16:54:37 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O2
NAME = fractol
HEADER = includes
MINILIBX_DIR = minilibx
MLX_FLAGS = -L $(MINILIBX_DIR) -l mlx -framework OpenGL -framework AppKit -framework OpenCL
SRC_DIR = srcs
SRC_FILES = main.c \
			error.c \
			free.c \
			fractal.c \
			input.c \
			input_mouse.c \
			draw_thread.c \
			draw_opencl.c \
			draw.c \
			menu.c \
			export_fdf.c \
			julia.c \
			mandelbrot.c \
			burningship.c \
			tricorn.c
LIBFT_DIR = libft
OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
WIN_X = 800
WIN_Y = 800
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "\n\033[0;33mCompiling final project.. \t\033[0;32mSuccess!\033m\017"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a $(OBJS)
	@echo "\033[0;31m------------- [ \033[0;36mEVERYTHING IS OK \033[0;31m] -----------\033m\017\033[0m"

$(OBJS_DIR):
	@echo "\033[0;31m------ [ \033[0;35m$(NAME) by lduqueno \033[0;31m] ------"
	@echo "\033[0;33mLinking MLX..\033[0m"
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "\033[0;33mLinking Libft..\033[0m"
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "\033[0;32mSuccess!\n\033[0m"
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -DWIN_X=$(WIN_X) -DWIN_Y=$(WIN_Y) -o $@ -c $< -I $(HEADER) -I $(LIBFT_DIR) -I $(MINILIBX_DIR)
	@echo "\033[0;33mCompiling $<.. \t\033[0;32mSuccess!\033m\017"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@make -C $(MINILIBX_DIR) clean > /dev/null
	@echo "\033[0;31mProject cleared!\033[0;0m"

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@rm -f $(NAME)

re: fclean all
