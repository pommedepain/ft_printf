# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 16:03:42 by btollie           #+#    #+#              #
#    Updated: 2018/11/17 20:38:05 by benjamintle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
INC_PATH = includes
SRC_PATH = srcs
OBJ_PATH = objs
CFLAGS = -Wall -Werror -Wextra

SRC_NAME = ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_strdup.c \
ft_strcpy.c \
ft_strncpy.c \
ft_isdigit.c \
ft_tolower.c \
ft_toupper.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strstr.c \
ft_strnstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_atoi.c \
ft_isalpha.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strndup.c \
ft_strnlen.c \
ft_isspace.c \
ft_strsplit.c \
ft_strcountsplit.c \
ft_strclen.c \
ft_putchar.c \
ft_putstr.c \
ft_putendl.c \
ft_putnbr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_itoa.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c

DIRS = $(sort $(filter-out %.c,$(subst /, ,$(SRC_NAME))))
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_PATH)

.PHONY: re all norme clean fclean
=======
#    By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:31:47 by psentilh          #+#    #+#              #
#    Updated: 2019/03/06 13:36:52 by pommedepin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a


# Compilation
CC= gcc

DEBUG= no
ifeq ($(DEBUG), yes)
	CFLAGS= -Wall -Werror -Wextra -g
else
	CFLAGS= -Wall -Werror -Wextra
endif


# Sources
SRCS= 	ft_memset.c\
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
		

DIR_OBJS= objs_libft/

OBJS= $(patsubst %.c,$(DIR_OBJS)%.o,$(SRCS))


# Others
HEADERS= -I .

>>>>>>> c8c9a7cc384cecaee232af672cdd61bb0c54d59d

all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "*** DEBUG MODE ACTIVATED ***"
endif

<<<<<<< HEAD
$(NAME): $(OBJ)
	@printf "\e[32;4m[Linking]:\e[0m %s\n" $@
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH) $(DIRS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(DIRS):
	@$(foreach DIR,$(DIRS),mkdir -p $(OBJ_PATH)/$(DIR);)

clean:
	@printf "\e[35;4m[Cleaning]:\e[0m\n"
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@printf "\e[31;4m[Cleaning]:\e[0m\n"
	@rm -fv $(NAME)

re: fclean all

norme:
	@printf "\e[31m"
	@norminette $(SRC) | grep -Eiw -B1 "Warning|Error" || true
	@norminette $(INC_PATH) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\e[0m\n"
=======
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"

$(DIR_OBJS)%.o: %.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "\033[36mCompiling $<...\033[0m"

clean: 
	@/bin/rm -rf $(DIR_OBJS)
	@echo "\033[35mCleaning $(DIR_OBJS)...\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all

.PHONY: re all clean fclean
>>>>>>> c8c9a7cc384cecaee232af672cdd61bb0c54d59d
