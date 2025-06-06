# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2024/12/19 22:26:59 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
NAME	=	get_next_line

## Paths to files
SRC_DIR	=	sources
INC_DIR	=	includes

## Source files
SRC		=	$(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c
HEADER	=	$(INC_DIR)/get_next_line.h

## Convert *.c files tnto *.o files
OBJ		=	$(SRC:%.c=%.o)

## Commands
RM		=	rm -f
CC		=	cc
LIBC	=	ar rcs
FLAGS	=	-Wall -Wextra -Werror

## Color Codes
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
YELLOW	=	\033[0;33m
RESET	=	\033[0m

## Targets
%.o:		%.c
			@ $(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@ echo "$(BLUE)Building get_next_line...$(RESET)"
			@ $(LIBC) $(NAME) $(OBJ)
			@ echo "$(GREEN)Done! get_next_line is now ready.$(RESET)"

clean:
			@ $(RM) $(OBJ)
			@ echo "$(CYAN)All get_next_line object files have been cleaned.$(RESET)"

fclean:
			@ $(RM) $(OBJ) $(NAME)
			@ echo "$(CYAN)All get_next_line excutable files have been cleaned.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re