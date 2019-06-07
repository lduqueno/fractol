# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 16:35:11 by lduqueno          #+#    #+#              #
#    Updated: 2019/06/05 18:07:57 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NORMAL = \033[0;0m

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC_FILES = lst/ft_lstadd.c		\
	lst/ft_lstdel.c				\
	lst/ft_lstdelone.c			\
	lst/ft_lstiter.c			\
	lst/ft_lstmap.c				\
	lst/ft_lstnew.c				\
	mem/ft_bzero.c				\
	mem/ft_memalloc.c			\
	mem/ft_memccpy.c			\
	mem/ft_memchr.c				\
	mem/ft_memcmp.c				\
	mem/ft_memcpy.c				\
	mem/ft_memdel.c				\
	mem/ft_memmove.c			\
	mem/ft_memset.c				\
	num/ft_atoi.c				\
	num/ft_is_base_valid.c		\
	num/ft_isdigit.c			\
	num/ft_itoa.c				\
	num/ft_putnbr.c				\
	num/ft_putnbr_base.c		\
	num/ft_putnbr_base_fd.c		\
	num/ft_putnbr_fd.c			\
	num/ft_putnbr_u_base.c		\
	num/ft_putnbr_u_base_fd.c	\
	str/ft_isalnum.c			\
	str/ft_isalpha.c			\
	str/ft_isascii.c			\
	str/ft_isprint.c			\
	str/ft_putchar.c			\
	str/ft_putchar_fd.c			\
	str/ft_putendl.c			\
	str/ft_putendl_fd.c			\
	str/ft_putstr.c				\
	str/ft_putstr_fd.c			\
	str/ft_strcat.c				\
	str/ft_strchr.c				\
	str/ft_strclr.c				\
	str/ft_strcmp.c				\
	str/ft_strcpy.c				\
	str/ft_strdel.c				\
	str/ft_strdup.c				\
	str/ft_strequ.c				\
	str/ft_striter.c			\
	str/ft_striteri.c			\
	str/ft_strjoin.c			\
	str/ft_strlcat.c			\
	str/ft_strlen.c				\
	str/ft_strmap.c				\
	str/ft_strmapi.c			\
	str/ft_strncat.c			\
	str/ft_strncmp.c			\
	str/ft_strncpy.c			\
	str/ft_strnequ.c			\
	str/ft_strnew.c				\
	str/ft_strnstr.c			\
	str/ft_strrchr.c			\
	str/ft_strsplit.c			\
	str/ft_strstr.c				\
	str/ft_strsub.c				\
	str/ft_strtrim.c			\
	str/ft_tolower.c			\
	str/ft_toupper.c			\
	str/ft_strequignorecase.c	\
	str/ft_strreplace.c			\
	str/ft_strjoin_free.c		\
	math/ft_sqrt.c				\
	math/ft_dsqrt.c				\
	math/ft_pow.c				\
	math/ft_dpow.c				\
	io/get_next_line.c			\
	printf/converter_base.c		\
	printf/converter_bonus.c	\
	printf/converter_double.c	\
	printf/converter_int.c		\
	printf/converter_ptr.c		\
	printf/converter_str.c		\
	printf/ft_strncpy_custom.c	\
	printf/flag_handler.c		\
	printf/flag_util.c			\
	printf/ft_ltoa_base.c		\
	printf/ft_ltoa.c			\
	printf/ft_printf.c			\
	printf/ft_snprintf.c		\
	printf/ft_sprintf.c			\
	printf/ft_vprintf.c			\
	printf/ft_vsprintf.c		\
	printf/ft_vsnprintf.c		\
	printf/ft_vprintf.c			\
	printf/ft_dprintf.c			\
	printf/ft_vdprintf.c		\
	printf/print_handler.c		\
	printf/buffer_util.c

OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
INCLUDES = includes
DIRS = $(sort $(filter-out %.c,$(subst /, ,$(SRC_FILES))))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(RED)------------- [ $(CYAN)DONE $(RED)] -------------$(NORMAL)"

$(OBJS_DIR):
	@echo "$(RED)------ [ $(MAGENTA)LIBFT by lduqueno$(RED) ] ------$(NORMAL)"
	mkdir $(OBJS_DIR)
	$(foreach DIR,$(DIRS),mkdir -p $(OBJS_DIR)/$(DIR);)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR) $(DIRS)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<
	@echo "$(YELLOW)Compiling $<.. $(GREEN)Success!$(NORMAL)"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
