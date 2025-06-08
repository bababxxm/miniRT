# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:44:55 by sklaokli          #+#    #+#              #
#    Updated: 2025/06/08 17:10:58 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

INC			:=	-I$(INC_DIR)
DEPS		:=	$(INC_DIR)/libft.h $(INC_DIR)/gnl.h $(INC_DIR)/gct.h

FILES		:=	\
				char/ft_isalnum.c \
				char/ft_isalpha.c \
				char/ft_isascii.c \
				char/ft_isdigit.c \
				char/ft_isprint.c \
				char/ft_tolower.c \
				char/ft_toupper.c \
				\
				int/ft_abs.c \
				int/ft_isint.c \
				\
				str/ft_strlen.c \
				str/ft_strlen_c.c \
				str/ft_strdup.c \
				str/ft_strcmp.c \
				str/ft_strncmp.c \
				str/ft_strchr.c \
				str/ft_strrchr.c \
				str/ft_strskip.c \
				str/ft_striteri.c \
				str/ft_strtrim.c \
				str/ft_substr.c \
				str/ft_strmapi.c \
				str/ft_strlcpy.c \
				str/ft_strlcat.c \
				str/ft_strjoin.c \
				str/ft_strnstr.c \
				str/ft_split.c \
				\
				conv/ft_itoa.c \
				conv/ft_atoi.c \
				conv/ft_atol.c \
				\
				mem/ft_malloc.c \
				mem/ft_calloc.c \
				mem/ft_bzero.c \
				mem/ft_free.c \
				mem/ft_free_2d.c \
				mem/ft_memset.c \
				mem/ft_memcpy.c \
				mem/ft_memcmp.c \
				mem/ft_memchr.c \
				mem/ft_memmove.c \
				\
				fd/ft_putchar_fd.c \
				fd/ft_putstr_fd.c \
				fd/ft_putendl_fd.c \
				fd/ft_putnbr_fd.c \
				\
				lst/ft_lstnew.c \
				lst/ft_lstsize.c \
				lst/ft_lstlast.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstadd_back.c \
				lst/ft_lstiter.c \
				lst/ft_lstdelone.c \
				lst/ft_lstclear.c \
				lst/ft_lstmap.c \
				\
				ps/ft_exit.c \
				ps/ft_fork.c \
				ps/ft_panic.c \
				\
				gnl/gnl.c \
				gnl/utils.c \
				\
				gct/gct.c

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

RM			:=	rm -f
CC			:=	cc
AR			:=	ar rcs
WFLAGS		:=	-Wall -Wextra -Werror

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(WFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	Makefile $(OBJ) $(DEPS)
			@ $(AR) $(NAME) $(OBJ)
			@ echo "$(GREEN)[OK] $(NAME) built succesfully.$(RESET)"

clean:		Makefile
			@ $(RM) -rf $(OBJ_DIR)
			@ echo "$(CYAN)$(NAME) object files cleaned.$(RESET)"

fclean:		Makefile
			@ $(RM) -rf $(OBJ_DIR) $(NAME)
			@ echo "$(CYAN)$(NAME) executable files cleaned.$(RESET)"

re:			Makefile fclean all

.PHONY:		all clean fclean re