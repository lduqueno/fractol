# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:12:10 by rlegan            #+#    #+#              #
#    Updated: 2019/05/21 14:21:48 by lduqueno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/bash

.PHONY: all clean fclean re

COLOR_GREEN = "\033[1;32;40m"
COLOR_RED = "\033[1;31;40m"
COLOR_YELLOW = "\033[1;33;40m"
COLOR_CYAN = "\033[1;36;40m"
COLOR_GRAY = "\033[1;38;5;244m"
COLOR_RESET = "\033[0m"

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC_NAME = ft_memset.c \
	ft_bzero.c \
	ft_memccpy.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c  \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strdup.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c  \
	ft_strsub.c \
	ft_strnequ.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_putchar.c \
	ft_putstr.c  \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_strrev.c \
	ft_swap.c \
	ft_sqrt.c \
	ft_is_prime.c \
	ft_recursive_power.c \
	ft_ltoa_base.c \
	ft_ltoa.c \
	ft_putnstr_fd.c \
	ft_printf.c \
	ptf_parser.c \
	ptf_display.c \
	ptf_flags.c \
	ptf_handle1.c \
	ptf_handle2.c \
	ptf_misc.c \
	ptf_handle_float.c \
	ptf_handle_float2.c \
	ptf_handlexo.c \
	ptf_handleu.c \
	ptf_handledi.c \
	ptf_handlep.c \
	ft_dprintf.c \
	ft_sprintf.c \
	ft_snprintf.c \
	get_next_line.c \
	ft_countnb.c \
	ft_tablen.c \
	ft_str_is_digit.c \
	ft_atoll.c \
	ft_atolu.c \
	ft_endswith.c \
	ft_isspace.c \
	ft_strsub_free.c \
	ft_countletter.c \
	reverse_32bits.c \
	reverse_16bits.c \
	ft_swapbytes.c \
	ft_strjoin_free.c \
	ft_strequignorecase.c \
	ft_strreplace.c


OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(OBJ_PATH)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@echo -en $(COLOR_GRAY)
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo -en $(COLOR_RESET)

$(NAME): $(OBJ)
	@echo -e $(COLOR_YELLOW)"Linking "$@"..."$(COLOR_RESET)
	@echo -en $(COLOR_GRAY)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo -en $(COLOR_RESET)
	@echo -e $(COLOR_GREEN)$(NAME)" successfully created."$(COLOR_RESET)

clean:
	@echo -e $(COLOR_RED)"Removing "$(OBJ_PATH)"..."$(COLOR_RESET)
	rm -Rf $(OBJ_PATH)

fclean: clean
	@echo -e $(COLOR_RED)"Removing "$(NAME)"..."$(COLOR_RESET)
	rm -f $(NAME)

re: fclean all
