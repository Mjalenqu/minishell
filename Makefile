# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mjalenqu <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/05 11:44:27 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/07/11 13:47:03 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=minishell
CC=@gcc
SRC=src/main.c src/check_arg.c src/exec.c src/ft_comp.c src/env.c src/var.c\
	src/error.c src/norm.c src/count_word.c src/fill_double.c src/fill_nothing.c\
	src/place.c src/place_v2.c src/place_v2_bis.c src/builtins.c
CFLAGS += -Wall -Wextra -Werror -g #-fsanitize=address

OBJ = $(SRC:.c=.o)

LIB_PATH=libft/libft.a

BLUE=\033[0;38;5;123m

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[1;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(LIGHT_GREEN)Compilation de la libft : "
	@make -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH) -Iincludes
	@echo "$(FLASH_GREEN)$(NAME) compilé et prêt à l'usage !\n"

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -o $@ -c $< -Iincludes
	@echo "$(DARK_BLUE.\c)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re : fclean all
