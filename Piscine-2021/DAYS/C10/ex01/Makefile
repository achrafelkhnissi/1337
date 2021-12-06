# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 14:59:44 by ael-khni          #+#    #+#              #
#    Updated: 2021/12/06 22:27:01 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I./includes
SRCS=$(wildcard srcs/*.c)
OBJS=$(SRCS:.c=.o)
BIN=ft_cat

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(INCLUDES) $(FLAGS) $(OBJS) -o $(BIN)
%.o: %.c ft_cat.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BIN)

.PHONY: all clean fclean
