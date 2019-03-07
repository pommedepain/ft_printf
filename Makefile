# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 15:17:57 by pommedepin        #+#    #+#              #
#    Updated: 2019/03/07 18:49:52 by pommedepin       ###   ########.fr        #
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
	@cd libft; make all
	@$(CC) $(CFLAGS) -c $< -o $@ -Ilibft/
	@echo "\033[36mCompiling $<...\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@cd libft; make clean
	@rm -f $(OBJS)
	@rm -rf obj/
	@echo "\033[35mCleaning $(OBJ_DIR)...\033[0m"

fclean: clean
	@cd libft; make fclean
	@rm -f $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all
