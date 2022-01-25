# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 23:57:36 by ael-khni          #+#    #+#              #
#    Updated: 2022/01/20 02:20:36 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OPERATION	= $(addprefix operations_bonus/, pa_push_a pb_push_b ra_rotate_a \
				  rb_rotate_b rr_ra_rb rra_reverse_rotate_a \
				  rrb_reverse_rotate_b rrr_rra_rrb sa_swap_a sb_swap_b \
				  ss_sa_sb)
CHECKS		= $(addprefix checks_bonus/, get_input is_sorted is_empty is_integer is_duplicates \
			  is_greater_than_int put_error)
UTILS		= $(addprefix utils_bonus/, ft_swap ft_atoi ft_strcmp ft_putstr \
			  ft_strjoin ft_strlen ft_strdup)
STACK		= $(addprefix stack_bonus/, create_new_elem push_elem stack_init \
			  push_elem_bottom free_stack pop_elem poop_elem)
FILES		= $(addprefix srcs_bonus/, checker $(STACK) $(OPERATION) $(UTILS) $(CHECKS))

SRC			= $(FILES:=_bonus.c)
OBJ			= $(FILES:=_bonus.o)
HEADER		= $(addprefix includes_bonus/, checker_bonus.h)
INCLUDES	= -I includes_bonus

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

#Debug
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus test norm

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(OPTS) -o $(NAME)
	@printf "$(GREEN)    - [BONUS] Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- [BONUS] Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(OPTS) $(INCLUDES) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- [BONUS] Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - [BONUS] Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- [BONUS] Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - [BONUS] Executable removed.$(RESET)\n"

re: fclean all
