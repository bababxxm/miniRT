# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:16:53 by sklaokli          #+#    #+#              #
#    Updated: 2025/05/08 18:40:52 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
NAME		=	miniRT
GCT			=	$(GCT_DIR)/gct.a
MLX			=	$(MLX_DIR)/build/libmlx42.a
LIB			=	$(GCT) $(MLX)

## Paths
SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc
GCT_DIR		:=	lib/gct
MLX_DIR		:=	lib/mlx

## Subdirectories
SUBDIRS		:=	main
main_FILES 	:=	main.c

## All sources and objects
SRC_FILES	:=	$(foreach dir,$(SUBDIRS), \
				$(addprefix $(SRC_DIR)/$(dir)/,$($(dir)_FILES)))

OBJ_FILES	:=	$(foreach dir,$(SUBDIRS), \
				$(addprefix $(OBJ_DIR)/$(dir)/,$($(dir)_FILES:.c=.o)))

## Include
INC			:=	-I$(INC_DIR) -I$(GCT_DIR)/include -I$(MLX_DIR)/include

## Commands
RM			:=	rm -f
CC			:=	cc
WFLAGS		:=	-Wall -Wextra -Werror
MLXFLAGS	:=	-Wunreachable-code -Ofast -g3 -ldl -lglfw -pthread -lm
VFLAGS		:=	--leak-check=full --show-leak-kinds=all

## Colors
CYAN		:=	\033[0;36m
GREEN		:=	\033[0;32m
BLUE		:=	\033[0;34m
RESET		:=	\033[0m

## Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(dir $@)
	@ echo "$(BLUE)Compiling $<$(RESET)"
	@ $(CC) $(WFLAGS) $(INC) -c $< -o $@

## Targets
all: $(NAME)

$(NAME): Makefile $(OBJ_FILES) $(LIB)
	@ $(CC) $(WFLAGS) $(MLXFLAGS) $(OBJ_FILES) $(GCT) $(MLX) $(INC) -o $(NAME)
	@ echo "$(GREEN)[OK] $(NAME) built successfully.$(RESET)"

$(LIB): Makefile
	@ if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@ if [ ! -d "$(GCT_DIR)" ]; then \
		git clone git@github.com:bababxxm/gct.git $(GCT_DIR); \
	fi
	@ cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && $(MAKE) -sC $(MLX_DIR)/build
	@ $(MAKE) -sC $(GCT_DIR)

lib_clean:
	@ $(MAKE) -sC $(GCT_DIR) clean

lib_fclean:
	@ $(RM) -rf $(MLX_DIR)/build
	@ $(MAKE) -sC $(GCT_DIR) fclean

clean: lib_clean
	@ $(RM) -rf $(OBJ_DIR)
	@ echo "$(CYAN)[Cleaned] object files removed.$(RESET)"

fclean: lib_fclean clean
	@ $(RM) -f $(NAME)
	@ echo "$(CYAN)[Cleaned] $(NAME) removed.$(RESET)"

re: fclean all

valgrind: $(NAME)
	@ valgrind $(VFLAGS) ./$(NAME)

.PHONY: all clean fclean re