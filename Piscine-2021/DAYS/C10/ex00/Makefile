# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 22:25:55 by ael-khni          #+#    #+#              #
#    Updated: 2021/12/06 22:26:14 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes
SRCS=$(wildcard srcs/*)
OBJS=$(notdir $(SRCS:.c=.o))
BIN=ft_display_file

.PHONY: all clean fclean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(INCLUDES) $(FLAGS) $? -o $@

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(BIN)
