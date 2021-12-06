CC=gcc
FLAGS=-Wall -Wextra -Werror
INCLUDES=-I includes
SRCS=$(wildcard srcs/*)
OBJS=$(notdir $(SRCS:.c=.o))
BIN=do-op

.PHONY: all clean fclean re

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(FLAGS) $? -o $@

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(BIN)

re: fclean all

