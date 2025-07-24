# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 16:45:27 by sklaokli          #+#    #+#              #
#    Updated: 2025/07/17 21:40:08 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	miniRT

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
				main/info.c \
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
				rt/camera.c \
				rt/ray.c \
				rt/trace.c \
				rt/light.c \
				rt/shadow.c \
				\
				utils/00.c \
				utils/01.c \
				utils/02.c \
				utils/03.c \
				utils/04.c \
				utils/05.c \
				utils/06.c

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

FLAGS		:=	$(WFLAGS) $(MLXFLAGS) 

$(BIN_DIR)/%.o:	$(SRC_DIR)/%.c $(DEP) 
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(WFLAGS) $(INC) -c $< -o $@

all:			$(NAME)

$(NAME):		Makefile $(LIB) $(BIN)
				@ $(CC) $(FLAGS) $(BIN) $(LIB) $(INC) -o $(NAME)
				@ echo "$(GREEN)[OK] $(NAME) built successfully.$(RESET)"

$(LIB):			Makefile
				@ cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
				@ $(MAKE) -sC $(MLX_DIR)/build
				@ $(MAKE) -sC $(LIBFT_DIR)

clean:			Makefile
				@ $(MAKE) -sC $(LIBFT_DIR) clean
				@ $(RM) -r $(BIN_DIR)
				@ echo "$(CYAN)$(NAME) BINect files cleaned.$(RESET)"

fclean: 		Makefile clean
				@ $(MAKE) -sC $(LIBFT_DIR) fclean
				@ $(RM) -r $(MLX_DIR)/build
				@ $(RM) $(NAME)
				@ echo "$(CYAN)$(NAME) executable files cleaned.$(RESET)"

re:				Makefile fclean all

leaks:			Makefile $(NAME)
				@ valgrind $(LFLAGS) ./$(NAME)

.PHONY:			all clean fclean re leaks