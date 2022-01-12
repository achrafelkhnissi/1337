# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:11:39 by ael-khni          #+#    #+#              #
#    Updated: 2022/01/12 09:23:04 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

FILES	= main srcs/display_banner \
		  srcs/parser/get_next_line srcs/parser/check_map \
		  srcs/parser/check_extention srcs/parser/ft_strcmp srcs/parser/check_ecp \
		  srcs/parser/check_walls srcs/parser/check_rectangular srcs/parser/get_map \
		  srcs/parser/ft_strchr srcs/parser/map_error srcs/parser/map_len \
		  srcs/parser/check_characters srcs/parser/check_dir srcs/parser/check_player \
		  srcs/parser/get_collectibles srcs/parser/ft_strlen srcs/parser/get_player_position \
		  srcs/window srcs/rendering srcs/player_moves \
		  srcs/moves srcs/ft_free srcs/free_map

SRC		= $(FILES:=.c)
OBJ		= $(FILES:=.o)
HEADER	= includes/so_long.h

BONUS_FILES = $(addprefix bonus/, $(FILES))
BONUS_SRC = $(BONUS_FILES:=_bonus.c)
BONUS_OBJ = $(BONUS_FILES:=_bonus.o)
BONUS_HEADER = bonus/so_long_bonus.h

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDE) $(LIBMLX) $(OPTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(OPTS) -c $< -o $@

play: all
	@printf "$(YELLOW)		- PLAYING ALL MAPS.. $(RESET)"
	@make clean -C ./
	@./$(NAME) maps/example1.ber
	@./$(NAME) maps/example2.ber
	@./$(NAME) maps/example3.ber

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

bonus:
	@$(MAKE) -C bonus
clean_bonus:
	@$(MAKE) clean -C bonus
fclean_bonus:
	@$(MAKE) fclean -C bonus
re_bonus:
	@$(MAKE) re -C bonus

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - Executable removed.$(RESET)\n"

re: fclean all
