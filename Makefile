# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:35:11 by rlegan            #+#    #+#              #
#    Updated: 2019/05/11 17:48:48 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

HEADER = includes

SRC_DIR = srcs

SRC_FILES = main.c \
			error.c \
			free.c \
			fractal.c \
			input.c

LIBFT_DIR = libft

OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "\n\033[0;33mCompiling final project.. \033[0;32mSuccess!\033m\017"
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT_DIR)/libft.a $(OBJS) -I $(LIBFT_DIR)
	@echo "\033[0;31m------------- [ \033[0;36mEVERYTHING IS OK \033[0;31m] -----------\033m\017\033[0m"

$(OBJS_DIR):
	@echo "\033[0;31m------ [ \033[0;35m$(NAME) by lduqueno and rlegan \033[0;31m] ------"
	@echo "\033[0;33mLinking Libft..\033[0m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0;32mSuccess!\n\033[0m"
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBFT_DIR)
	@echo "\033[0;33mCompiling $<.. \033[0;32mSuccess!\033m\017"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
