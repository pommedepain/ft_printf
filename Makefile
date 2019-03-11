# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 15:17:57 by pommedepin        #+#    #+#              #
#    Updated: 2019/03/07 19:16:11 by benjamintle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC =	conversion_util.c\
		conversion.c\
		ft_printf.c\
		main.c\
		parsing_util.c\
		parsing.c\
		printf_str_manager.c\
		util.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_word_count.c\
		ft_letter_count.c\
		ft_tab_filling.c\
		ft_itoa.c\
		ft_digit_len.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		get_next_line.c\
		ft_print_words_tables.c\
		ft_tabdel.c\
		ft_strlens.c\
		ft_strjoinfs1.c\
		ft_strjoinfs2.c\
		ft_strjoins.c\
		ft_strdups.c\
		ft_strcmps.c\
		ft_strchrs.c\
		ft_str_dupfree.c\
		ft_no_whitespaces.c\
		ft_convert_base.c\
		ft_strcountsplit.c\
		ft_strtrimc.c\
		ft_strclen.c\
		ft_tabcpy.c\
		ft_strndup.c\
		ft_strnlen.c\
		

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./inc/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libftprintf.h

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"
	@echo "\033[32m\033[1m$(NAME) all done and ready to go ! 🤗 \033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[36mCompiling $<...\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf obj/
	@echo "\033[35mCleaning $(OBJ_DIR)...\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all
