# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:11:39 by ael-khni          #+#    #+#              #
#    Updated: 2022/01/10 18:51:38 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long_bonus

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

BONUS_FILES	= main srcs_bonus/display_banner \
		  srcs_bonus/parser_bonus/gnl srcs_bonus/parser_bonus/check_map \
		  srcs_bonus/parser_bonus/check_extention srcs_bonus/parser_bonus/ft_strcmp srcs_bonus/parser_bonus/check_ecp \
		  srcs_bonus/parser_bonus/check_walls srcs_bonus/parser_bonus/check_rectangular srcs_bonus/parser_bonus/get_map \
		  srcs_bonus/parser_bonus/ft_strchr srcs_bonus/parser_bonus/map_error srcs_bonus/parser_bonus/map_len \
		  srcs_bonus/parser_bonus/check_characters srcs_bonus/parser_bonus/check_dir \
		  srcs_bonus/parser_bonus/get_collectibles srcs_bonus/parser_bonus/ft_strlen srcs_bonus/parser_bonus/get_player_position \
		  srcs_bonus/window srcs_bonus/rendering srcs_bonus/player_moves srcs_bonus/ft_swap \
		  srcs_bonus/moves srcs_bonus/ft_free srcs_bonus/enemy_moves srcs_bonus/ft_itoa \
		  srcs_bonus/ft_strjoin srcs_bonus/reset srcs_bonus/free_map
BONUS_SRC		= $(BONUS_FILES:=_bonus.c)
BONUS_OBJ		= $(BONUS_FILES:=_bonus.o)
BONUS_HEADER	= includes_bonus/so_long_bonus.h

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

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):  $(BONUS_OBJ) $(BONUS_HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(BONUS_OBJ) $(INCLUDE) $(LIBMLX) $(OPTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS)$(GREEN) - [BONUS] executable ready.$(RESET)\n"

%.o: %.c $(BONUS_HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(OPTS) -c $< -o $@

play: all
	@printf "$(YELLOW)     - [bonus] Playing all maps... $(RESET)\n"
	@make -C ./ clean
	@./$(NAME) maps/example1.ber
	@./$(NAME) maps/example2.ber
	@./$(NAME) maps/example3.ber

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

clean:
	@ $(RM) $(BONUS_OBJ)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Removing object files ... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - [BONUS] Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Removing $(NAME)... $(RESET)\n"
	@printf "$(_INFO)$(YELLOW) - [BONUS] Executable removed.$(RESET)\n"

re: fclean all
