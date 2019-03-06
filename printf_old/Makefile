# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by tplessis          #+#    #+#              #
#    Updated: 2019/02/07 14:27:44 by benjamintle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.test
CC = clang
INC_PATH = includes
SRC_PATH = srcs
OBJ_PATH = objs
LIBS_NAME = libft
SRC_NAME = 	main.c\
			ft_printf.c\
			pf_manager.c\
			pf_strreader.c\
			pf_argreader.c\
			pf_initstruct.c\
			pf_isflag.c\
			pf_issize.c\
			pf_isconv.c


OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIBS = $(foreach LIB, $(LIBS_NAME), $(LIB)/$(LIB).a)
CFLAGS = ##-Wall -Werror -Wextra -fsanitize=address -g3
CPPFLAGS = -I $(INC_PATH) $(addprefix -I ,$(addsuffix /$(INC_PATH),$(LIBS_NAME)))
CLFLAGS = $(addprefix -L ,$(LIBS_NAME)) $(addprefix -,$(subst ib,,$(LIBS_NAME)))

.PHONY: re all norme clean fclean

all: $(NAME)

$(NAME): $(OBJ) | $(LIBS)
	@printf "\e[32;4m[Linking]:\e[0m %s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(CLFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBS):
	@printf "\e[34;4m[Making]:\e[0m %s\n" $(patsubst %/,%,$(dir $@))
	@make -C $(dir $@) all

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@printf "\e[35;4m[Cleaning]:\e[0m\n"
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)
	@$(foreach LIB, $(LIBS_NAME), make -C $(LIB) clean;)

fclean: clean
	@printf "\e[31;4m[Cleaning]:\e[0m\n"
	@rm -fv $(NAME)
	@$(foreach LIB, $(LIBS), rm -f $(LIB);)

re: fclean all

norme:
	@printf "\e[31m"
	@norminette $(SRC) | grep -Eiw -B1 "Warning|Error" || true
	@norminette $(INC_PATH) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\e[0m\n"
	$(foreach LIB, $(LIBS_NAME), make -C $(LIB) norme;)
