CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I $(wildcard *.h)
SRCS=$(wildcard srcs/*.c)
OBJS=$(notdir $(SRCS:.c=.o))
BIN=ft_advanced_do-op

.PHONY: all clean fclean re

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(FLAGS) $? -o $@
	rm $^

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(BIN)

re: fclean all

