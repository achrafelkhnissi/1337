# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:11:39 by ael-khni          #+#    #+#              #
#    Updated: 2021/12/15 16:45:19 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

FILES	= main display_banner
SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER	= so_long.h

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@ $(CC) $(OBJ) $(INCLUDE) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS) executable ready.\n"

%.o: %.c
	@ $(CC) -Wall -Wextra -Werror  -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(_INFO) executable removed.\n"

re: fclean all
