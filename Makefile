# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 15:27:23 by pommedepin        #+#    #+#              #
#    Updated: 2019/03/06 12:55:42 by pommedepin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Compilation
CC= gcc

DEBUG= no
ifeq ($(DEBUG), yes)
	FLAGS= -Wall -Werror -Wextra -g3
else
	FLAGS= -Wall -Werror -Wextra
endif

# Sources
SRCS =	display.c \
		free_stuff.c \
		list.c \
		parsing.c \
		utils.c

# Objects
OBJS= $(patsubst %.c,$(DIR_OBJS)%.o,$(SRCS))

DIR_OBJS= objs_printf/


# Include
HEADERS = -I libftprintf.h


all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "*** DEBUG MODE ACTIVATED ***"
endif

$(NAME): $(OBJS)
	@cd libft; make all
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"

$(DIR_OBJS)%.o: %.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)
	@echo "\033[36mCompiling $<...\033[0m"

clean:
	@cd libft; make clean
	@/bin/rm -rf $(DIR_OBJS)
	@echo "\033[35mCleaning $(DIR_OBJS)...\033[0m"

fclean: clean
	@cd libft; make fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all

.PHONY: all clean fclean re

