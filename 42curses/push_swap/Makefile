# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 07:40:22 by ael-khni          #+#    #+#              #
#    Updated: 2022/01/20 14:34:22 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

STACK		= $(addprefix stack/, create_new_elem free_stack pop_elem poop_elem \
			  push_elem push_elem_bottom stack_init)
OPERATION	= $(addprefix operations/, pa_push_a pb_push_b ra_rotate_a \
				  rb_rotate_b rr_ra_rb rra_reverse_rotate_a \
				  rrb_reverse_rotate_b rrr_rra_rrb sa_swap_a sb_swap_b \
				  ss_sa_sb)
CHECKS		= $(addprefix checks/, get_input is_sorted is_empty is_integer is_duplicates \
			  is_greater_than_int put_error)
UTILS		= $(addprefix utils/, ft_swap ft_atoi ft_strcmp ft_putstr)
ALGO		= $(addprefix algorithm/, naive_sort chunks_sort sort_three \
			  get_chunk_elem get_elem_index get_max get_min put_to_stack_a \
			  put_chunk_elems)
FILES		= $(addprefix srcs/, push_swap $(STACK) $(OPERATION) $(UTILS) $(CHECKS) $(ALGO))

SRC			= $(FILES:=.c)
OBJ			= $(FILES:=.o)
HEADER		= $(addprefix includes/, push_swap.h)
INCLUDES	= -I includes

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
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(OPTS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(OPTS) $(INCLUDES) -c $< -o $@

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

test: all
	@printf "\n$(YELLOW)	- Testing $(ARG) random numbers.. $(RESET)\n\n"
	@sh testing/testing.sh $(ARG) 

bonus:
	@$(MAKE) -C checker_bonus
clean_bonus:
	@$(MAKE) clean -C checker_bonus
fclean_bonus:
	@$(MAKE) fclean -C checker_bonus
re_bonus:
	@$(MAKE) re -C checker_bonus

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all
