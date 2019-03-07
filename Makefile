# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 15:27:23 by pommedepin        #+#    #+#              #
#    Updated: 2019/03/07 16:10:38 by benjamintle      ###   ########.fr        #
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
SRCS =	conversion_util.c \
		conversion.c \
		ft_printf.c \
		parsing_util.c \
		parsing.c\
		printf_str_manager\
		util.c

# Objects
OBJS= 

DIR_OBJS= objs_printf/


# Include
HEADERS = -I libftprintf.h


all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "*** DEBUG MODE ACTIVATED ***"
endif

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"

$(OBJS): $(DIR_OBJS)
	@mkdir -p $(DIR_OBJS)
	$(patsubst %.c,$(DIR_OBJS)%.o,$(SRCS))

$(LIBFT):
	@cd libft; make all


$(DIR_OBJS)%.o: %.c
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
