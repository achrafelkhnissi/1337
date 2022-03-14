# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 16:06:58 by ael-khni          #+#    #+#              #
#    Updated: 2022/03/13 15:21:40 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

UTILS		= $(addprefix utils/, ft_atoi ft_puterr ft_strlen ft_calloc ft_get_time)
INIT		= $(addprefix init/, ft_init_all ft_init_philos ft_get_args ft_check_info \
								ft_init_mutex)
ACT			= $(addprefix actions/, ft_down_fork ft_grab_fork ft_join_free ft_philo_actions ft_print_msg \
								ft_sleep_then_think ft_eating)
FILES		= $(addprefix srcs/, philo $(INIT) $(UTILS) $(ACT))

SRC			= $(FILES:=.c)
OBJ			= $(FILES:=.o)
HEADER		= $(addprefix includes/, philo.h)
INCLUDES	= -I includes
PTHREAD		= -pthread

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

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus norm

all: $(NAME)

$(NAME):  $(OBJ) $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(OBJ) $(INCLUDES) $(PTHREAD) $(OPTS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY) 	- Making object file $(notdir $@) from source file $(notdir $<) ... $(RESET)\n"
	@ $(CC) -Wall -Wextra -Werror $(PTHREAD) $(OPTS) $(INCLUDES) -c $< -o $@

norm:
	@printf "$(CURSIVE)$(GRAY)"
	@norminette
	@printf "$(RESET)"

clean:
	@ $(RM) $(OBJ)
	@printf "$(CURSIVE)$(GRAY)	- Removing object files ... $(RESET)\n"
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all
