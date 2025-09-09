# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 16:45:27 by sklaokli          #+#    #+#              #
#    Updated: 2025/09/04 02:02:45 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minirt

SRC_DIR		:=	src
BIN_DIR		:=	bin
INC_DIR		:=	inc
LIB_DIR		:=	lib

DEP			:=	$(addprefix $(INC_DIR)/, minirt.h)
LIBFT_DIR	:=	$(addprefix $(LIB_DIR)/, libft)
MLX_DIR		:=	$(addprefix $(LIB_DIR)/, mlx42)

INC			:=	-I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(MLX_DIR)/include

LIBFT		:=	$(LIBFT_DIR)/libft.a
MLX			:=	$(MLX_DIR)/build/libmlx42.a

LIB			:=	$(LIBFT) $(MLX)

FILES		:=	main/main.c \
				\
				init/reader.c \
				init/parser.c \
				init/element.c \
				init/object.c \
				\
				obj/sphere.c \
				obj/plane.c \
				obj/cylinder.c \
				\
				rt/hook.c \
				rt/keybinds.c \
				rt/ray.c \
				rt/trace.c \
				rt/light.c \
				rt/shadow.c \
				\
				utils/color.c \
				utils/display.c \
				utils/display2.c \
				utils/equation.c \
				utils/parser.c \
				utils/program.c \
				utils/vector.c \
				utils/vector2.c

SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
BIN			:=	$(addprefix $(BIN_DIR)/, $(FILES:.c=.o))

COMPILED	:=	0
TOTAL_FILES	:=	$(words $(BIN))

CYAN		:=	\033[1;36m
GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
BLUE		:=	\033[1;34m
YELLOW		:=	\033[1;33m
RESET		:=	\033[0m

CC			:=	cc
RM			:=	rm -f
AR			:=	ar rcs

WFLAGS		:=	-Wall -Wextra -Wextra -Ofast
MLXFLAGS	:=	-ldl -lglfw -pthread -lm
LFLAGS		:=	--leak-check=full --show-leak-kinds=all
FDFLAGS		:=	--track-fds=yes --trace-children=yes
VFLAGS		:=	$(LFLAGS) $(FDFLAGS)

FLAGS		:=	$(WFLAGS) $(MLXFLAGS) 

$(BIN_DIR)/%.o:	$(SRC_DIR)/%.c $(DEP) 
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(WFLAGS) $(INC) -c $< -o $@

all:			$(NAME)

$(NAME):		Makefile $(LIB) $(BIN)
				@ $(CC) $(BIN) $(LIB) $(INC) -o $(NAME) $(FLAGS)
				@ echo "$(GREEN)[OK] $(NAME) built successfully.$(RESET)"

$(LIB):			Makefile
				@ cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
				@ $(MAKE) -sC $(MLX_DIR)/build
				@ $(MAKE) -sC $(LIBFT_DIR)

clean:			Makefile
				@ $(MAKE) -sC $(LIBFT_DIR) clean
				@ $(RM) -r $(BIN_DIR)
				@ echo "$(CYAN)$(NAME) object files cleaned.$(RESET)"

fclean: 		Makefile clean
				@ $(MAKE) -sC $(LIBFT_DIR) fclean
				@ $(RM) -r $(MLX_DIR)/build
				@ $(RM) $(NAME)
				@ echo "$(CYAN)$(NAME) executable files cleaned.$(RESET)"

re:				Makefile fclean all

valgrind:		Makefile $(NAME)
				@ valgrind $(VFLAGS) ./$(NAME) scene/basic.rt

.PHONY:			all clean fclean re valgrind