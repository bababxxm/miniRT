# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:16:53 by sklaokli          #+#    #+#              #
#    Updated: 2025/06/06 15:45:42 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT

SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

LIBFT_DIR	:=	lib/libft
GCT_DIR		:=	lib/gct
GNL_DIR		:=	lib/gnl
MLX_DIR		:=	lib/mlx

INC			:=	-I$(INC_DIR) -I$(LIBFT_DIR)/inc \
				-I$(GCT_DIR)/inc -I$(GNL_DIR)/includes \
				-I$(MLX_DIR)/include

DEP			:=	$(INC_DIR)/miniRT.h

LIBFT		:=	bin/libft.a
GCT			:=	bin/gct.a
MLX			:=	bin/libmlx42.a
GNL			:=	bin/gnl.a

LIB			:=	$(GCT) $(MLX)

FILES		:=	main.c

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

COMPILED	:=	0
TOTAL_FILES	:=	$(words $(OBJ))

CYAN		:=	\033[1;36m
GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
BLUE		:=	\033[1;34m
YELLOW		:=	\033[1;33m
RESET		:=	\033[0m

CC			:=	cc
RM			:=	rm -f
AR			:=	ar rcs
WFLAGS		:=	-Wall -Wextra -Werror
VFLAGS		:=	--leak-check=full --show-leak-kinds=all
FDFLAGS		:=	--track-fds=yes --trace-children=yes
HFLAGS		:=	--tool=helgrind

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(DEPS)
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(WFLAGS) $(INC) -c $< -o $@

all:			$(NAME)

$(NAME):		Makefile $(OBJ)
				@ $(CC) $(WFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(GNL) $(GCT) $(MLX) $(INC) -o $(NAME)
				@ echo "$(GREEN)[OK] $(NAME) built successfully.$(RESET)"

$(LIB):			Makefile $(OBJ)
				@ cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && $(MAKE) -sC $(MLX_DIR)/build
				@ $(MAKE) -sC $(LIBFT_DIR)
				@ $(MAKE) -sC $(GCT_DIR)

clone:			Makefile
				@ if [ ! -d "$(LIBFT_DIR)" ]; then git clone git@github.com:bababxxm/libft.git $(LIBFT_DIR); fi
				@ if [ ! -d "$(GCT_DIR)" ]; then git clone git@github.com:bababxxm/gct.git $(GCT_DIR); fi
				@ if [ ! -d "$(MLX_DIR)" ]; then git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); fi

lib_clean:		Makefile
				@ if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -sC $(LIBFT_DIR) clean; fi
				@ if [ -d "$(GCT_DIR)" ]; then $(MAKE) -sC $(GCT_DIR) clean; fi

lib_fclean:		Makefile
				@ if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -sC $(LIBFT_DIR) fclean; fi
				@ if [ -d "$(GCT_DIR)" ]; then $(MAKE) -sC $(GCT_DIR) fclean; fi
				@ if [ -d "$(MLX_DIR)" ]; then $(RM) -rf $(MLX_DIR)/build; fi

clean:			Makefile
				@ $(RM) -rf $(OBJ_DIR)
				@ echo "$(CYAN)$(NAME) object files cleaned.$(RESET)"

fclean: 		Makefile clean
				@ $(RM) -f $(NAME)
				@ echo "$(CYAN)$(NAME) executable files cleaned.$(RESET)"

re:				Makefile fclean all

valgrind:		Makefile $(NAME)
				@ valgrind $(VFLAGS) ./$(NAME)

.PHONY:			all clean fclean re clone valgrind