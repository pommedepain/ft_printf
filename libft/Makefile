# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 17:58:19 by cajulien          #+#    #+#              #
#    Updated: 2019/01/10 17:02:39 by cajulien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
FLAGS= -Wall -Wextra -Werror
SRC=            ft_memset.c \
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
                ft_isdigit.c \
                ft_isalnum.c \
                ft_isascii.c \
                ft_isprint.c \
                ft_toupper.c \
                ft_tolower.c \
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
                ft_strsplit.c \
                ft_itoa.c \
                ft_putchar.c \
                ft_putstr.c \
                ft_putendl.c \
                ft_putnbr.c \
                ft_putchar_fd.c \
                ft_putstr_fd.c \
                ft_putendl_fd.c \
                ft_putnbr_fd.c \
                ft_lstnew.c \
                ft_lstdelone.c \
                ft_lstdel.c \
                ft_lstadd.c \
                ft_lstiter.c \
                ft_lstmap.c \
                ft_strchrs.c \
                ft_strlens.c \
                ft_strcmps.c \
                ft_strdups.c \
                ft_strjoins.c \
                ft_convert_base.c \
                ft_no_whitespaces.c \
                ft_strjoinfs1.c \
                ft_strjoinfs2.c
OBJ = ${SRC:.c=.o}
HEADER= libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $^ -I $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
