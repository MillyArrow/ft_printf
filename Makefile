# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrow <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 20:11:40 by marrow            #+#    #+#              #
#    Updated: 2020/02/16 05:51:27 by marrow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes -I $(LIB_FT_DIR)/includes

LIB_FT_DIR = libft
LIB_FT_FILE = $(LIB_FT_DIR)/libft.a

LIB_FT_FLAGS = -L $(LIB_FT_DIR) -lft

O_DIR = objects/
SRC_DIR = sources/

C_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')
O_FILES = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o, $(C_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
O_DIRS = $(patsubst $(SRC_DIR)%, $(O_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(O_DIRS) $(O_FILES)
	@make -C $(LIB_FT_DIR)
	@cp $(LIB_FT_FILE) $(NAME)
	@ar rc $(NAME) $(O_FILES)
	@echo "make: Done building \`$(NAME)'."

$(O_DIRS):
	@mkdir -vp $(O_DIRS)

$(LIB_FT_FILE):
	@make -C $(LIB_FT_DIR)

$(O_DIR)%.o: $(SRC_DIR)%.c
	@clang $(FLAGS) $(INCLUDES)  -o $@ -c $<

clean:
	@make -C $(LIB_FT_DIR) clean
	@rm -rf $(O_DIR)
	@echo "make: Done clean of \`$(NAME)'."


fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."


re: fclean all
	@echo "make: Done recompile everything of \`$(NAME)'."

lclean:
	@rm -rf $(O_DIR)
	@rm -f $(NAME)
	@echo "make: Done local clean of \`$(NAME)'."

lrc: lclean all
	@echo "make: Done local recompile of \`$(NAME)'."